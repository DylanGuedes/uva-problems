#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR(i,j,k)for(int i=j;i<k;++i)
int ranks[25200];
int parent[25200];

struct edge {
        int x, y, z;
};

vector<edge> edges;

bool myfunc(edge e1, edge e2)
{
        return e1.z < e2.z;
}

int union_find(int x)
{
        if (x == parent[x])
                return x;
        else
                return parent[x] = union_find(parent[x]);
}

void make_union(int x, int y)
{
        int rootx = union_find(x);
        int rooty = union_find(y);
        if (ranks[rootx] >= ranks[rooty]) {
                parent[rooty] = rootx;
                ranks[rootx]++;
        } else {
                parent[rootx] = rooty;
                ranks[rooty]++;
        }
}

int main()
{
        int t, n, m, a;

        scanf("%d", &t);
        FOR(z, 0, t) {
                edge e;
                edges.clear();
                scanf("%d%d%d", &n, &m, &a);
                FOR(i, 0, m) {
                        scanf("%d%d%d", &e.x, &e.y, &e.z);
                        edges.push_back(e);
                }

                sort(edges.begin(), edges.end(), myfunc);
                FOR(i, 0, n+2)
                        parent[i] = i;
                memset(ranks, 0, sizeof ranks);
                int edges_size = edges.size();
                int total = 0;
                FOR(i, 0, edges_size) {
                        if (union_find(edges[i].x) != union_find(edges[i].y)) {
                                if (edges[i].z >= a)
                                        continue;
                                make_union(edges[i].x, edges[i].y);
                                total += edges[i].z;
                        }
                }
                int idx = 0;
                FOR(i, 0, n) {
                        if (union_find(i) != union_find(i+1)) {
                                total += a;
                                idx += 1;
                                make_union(i, i+1);
                        }
                }
                printf("Case #%d: %lld %d\n", z+1, total, idx);
        }
        return 0;
}
