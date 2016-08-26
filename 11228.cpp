#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int x[1010];
int y[1010];
int father[1010];
int ranks[1010];

struct edge {
    int x, y;
    double z;
};

int union_find(int x)
{
    if (x == father[x])
        return x;
    else
        return father[x] = union_find(father[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);
    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]+=1;
        father[rooty] = rootx;
    } else {
        ranks[rooty]+=1;
        father[rootx] = rooty;
    }
}

vector<edge> edges;

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int main()
{
    int w;
    long long int n, r;
    int t;
    int actual_case=0;
    scanf("%d", &t);

    FOR(z, 0, t) {
        scanf("%lld%lld", &n, &r);
        FOR(i, 0, n) {
            scanf("%d%d", &x[i], &y[i]);
        }
        edges.clear();
        edge e;
        FOR(i, 0, n) {
            FOR(j, i+1, n) {
                e.x = i;
                e.y = j;
                double xx = x[j]-x[i];
                xx = pow(xx, 2);
                double yy = y[j]-y[i];
                yy = pow(yy,2);
                e.z = sqrt(xx+yy);
                edges.push_back(e);
            }
        }

        sort(edges.begin(), edges.end(), myfunc);
        FOR(i, 0, n+2) {
            father[i] = i;
        }
        memset(ranks, 0, sizeof ranks);

        int mysize = edges.size();
        double total = 0;
        int total_states = 1;
        double total2 = 0;
        FOR(i, 0, mysize) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                if (edges[i].z >= r) {
                    total_states += 1;
                    total2 += edges[i].z;
                } else {
                    total += edges[i].z;
                }
                make_union(edges[i].x, edges[i].y);
            }
        }

        actual_case++;
        printf("Case #%d: %lld %.lf %.lf\n", actual_case, total_states, total, total2);
    }
    return 0;
}
