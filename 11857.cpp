#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

struct edge
{
    int x, y, z;
};

vector<edge> edges;
int ranks[100000];
int father[100000];

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int union_find(int x)
{
    if (father[x] == x)
        return x;
    else
        return father[x] = union_find(father[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);
    if (ranks[rootx] >= ranks[rooty]) {
        father[rooty] = rootx;
        ranks[rootx]+=1;
    } else {
        father[rootx] = rooty;
        ranks[rooty]+=1;
    }
}

int main()
{
    int n, m, origin, destination, weight;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (not (n|m))
            return 0;
        edges.clear();
        edge e;
        FOR(i, 0, m) {
            scanf("%d", &e.x);
            scanf("%d", &e.y);
            scanf("%d", &e.z);
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end(), myfunc);
        memset(ranks, 0, sizeof ranks);
        FOR(i, 0, n) {
            father[i] = i;
        }

        int mysize = edges.size();
        int val = -1;
        FOR(i, 0, mysize) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);
                val = max(val, edges[i].z);
            }
        }

        bool possible = true;
        FOR(i, 0, n-1) {
            if (union_find(i) != union_find(i+1)) {
                possible = false;
                break;
            }
        }

        if (val != -1 && possible)
            printf("%d\n", val);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
