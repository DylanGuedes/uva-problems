#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MEMSET(i) memset(i, 0, sizeof i);

int father[800];
int ranks[800];

struct edge
{
    int x;
    int y;
    double z;
};

vector<edge> edges;

edge arr[800];

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
        father[rooty] = rootx;
        ranks[rootx]++;
    } else {
        father[rootx] = rooty;
        ranks[rooty]++;
    }
}

int main()
{
    int n;
    int origin, destiny;
    while (cin >> n) {
        FOR(i,0,n) {
            cin >> arr[i].x >> arr[i].y;
        }

        int total_edges = 0;
        edge e;
        edges.clear();
        FOR(i,0,n) {
            FOR(j,i+1,n) {
                double x0 = arr[i].x;
                double x1 = arr[j].x;
                double y0 = arr[i].y;
                double y1 = arr[j].y;

                double eucl_x = x1-x0;
                double eucl_y = y1-y0;

                eucl_x = eucl_x * eucl_x;
                eucl_y = eucl_y * eucl_y;

                double euclid = sqrt(eucl_x + eucl_y);
                e.x = i;
                e.y = j;
                e.z = euclid;
                edges.push_back(e);
                ++total_edges;
            }
        }

        MEMSET(ranks);
        FOR(i, 0, n+2) {
            father[i] = i; 
        }

        cin >> n;
        FOR(i, 0, n) {
            cin >> origin >> destiny;
            // printf("make union between %d and %d\n", origin-1, destiny-1);
            make_union(origin-1, destiny-1);
        }

        double total = 0;
        sort(edges.begin(), edges.end(), myfunc);
        //
        // printf("all edges:");
        // for (auto it : edges) {
        //     printf("%d to %d, weight: %f\n", it.x, it.y, it.z);
        // }

        int mysize = edges.size();
        FOR(i, 0, mysize) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);
                // printf("union between %d and %d\n", edges[i].x, edges[i].y);
                total += edges[i].z;
            }
        }

        printf("%.2f\n", total);

    }
    return 0;
}
