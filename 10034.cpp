#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge {
    int x;
    int y;
    double z;
};

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

#define FOR(i, j, k)for(int i=j; i < k;++i)

vector<edge> edges;
edge graph[120];
int father[120];
int ranks[120];

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

int main(int argc, char const *argv[])
{
    int n, t;
    double myx, myy;
    cin >> t;
    FOR(z, 0, t) {
        if (z != 0)
            printf("\n");
        cin >> n;
        FOR(i, 0, n) {
            cin >> myx >> myy;
            graph[i].x = myx;
            graph[i].y = myy;
        }

        edges.clear();

        edge e;
        FOR(i, 0, n) {
            FOR(j,i,n) {
                double eucl_x = graph[j].x - graph[i].x;
                eucl_x = eucl_x * eucl_x;
                double eucl_y = graph[j].y - graph[i].y;
                eucl_y = eucl_y * eucl_y;
                double part = eucl_x + eucl_y;
                part = sqrt(part);
                e.x = i;
                e.y = j;
                e.z = part;
                edges.push_back(e);
            }
        }
        memset(ranks, 0, sizeof ranks);

        FOR(i, 0, n+5) {
            father[i] = i;
        }

        double total = 0;
        sort(edges.begin(), edges.end(), myfunc);
        for (auto it : edges) {
            if (union_find(it.x) != union_find(it.y)) {
                make_union(it.x, it.y);
                total += it.z;
            }
        }

        printf("%.2f\n", total);
    }
    return 0;
}
