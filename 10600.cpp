#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j, k) for(int i=j; i < k; ++i)
#define MEMSET(i) memset(i, 0, sizeof i)

int father[110];
int ranks[110];

struct edge
{
    int x;
    int y;
    int z;
};

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int union_find(int x)
{
    if (father[x] == x)
        return x;
    else
        return union_find(father[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);
    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        father[rooty] = rootx;
    } else {
        ranks[rooty]++;
        father[rootx] = rooty;
    }
}

vector<edge> edges;

int main()
{
    int n, m;
    int origin, destiny, weight;
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        edges.clear();

        edge e;
        FOR(i, 0, m) {
            cin >> origin >> destiny >> weight;
            e.x = origin-1;
            e.y = destiny-1;
            e.z = weight;
            edges.push_back(e);
        }


        int mysize = edges.size();
        int mst_total = 0;
        int elements = 0;

        sort(edges.begin(), edges.end(), myfunc);
        FOR(i, 0, n+2) {
            father[i] = i;
        }
        MEMSET(ranks);

        int union_count = 0;
        set<int> myset;
        FOR(i, 0, mysize) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);
                union_count++;
                mst_total += edges[i].z;
                myset.insert(i);
            }
        }

        int second_best_cost = 0xffffff;
        bool has_2nd_mst = false;
        FOR(i, 0, mysize) {
            if (myset.count(i) == 0)
                continue;
            MEMSET(ranks);
            FOR(j, 0, n+2) {
                father[j] = j;
            }
           
            int new_cost = 0;
            FOR(j, 0, mysize) {
                if (j != i) {
                    if (union_find(edges[j].x) != union_find(edges[j].y)) {
                        make_union(edges[j].x, edges[j].y);
                        new_cost += edges[j].z;
                    }
                }
            }

            bool possible = true;
            FOR(j, 0, n) {
                FOR(k, j+1, n) {
                    if (union_find(father[j]) != union_find(father[k])) {
                        possible = false;
                    }
                }
            }

            if (possible && new_cost >= mst_total) {
                // printf("mst found!\n");
                // printf("removed: %d\n", edges[i].z);
                has_2nd_mst = true;
                second_best_cost = min(second_best_cost, new_cost);
                // printf("cost: %d\n", new_cost);
            }
        }

        if (has_2nd_mst)
            printf("%d %d\n", mst_total, second_best_cost);
        else
            printf("%d %d\n", mst_total, mst_total);
    }
    return 0;
}
