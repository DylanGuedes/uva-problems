#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

#define ii pair<int, int>

struct edge
{
    int x;
    int y;
    double z;
};

struct n_edge
{
    int x;
    int y;
};

int ranks[210];
int father[210];
vector<edge> edges;
n_edge arr[210];
int visited[210];

bool myfunc(edge e1, edge e2)
{
    return e1.z  < e2.z;
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
    if (ranks[rootx] > ranks[rooty]) {
        ranks[rootx]++;
        father[rooty] = rootx;
    } else {
        ranks[rooty]++;
        father[rootx] = rooty;
    }
}

int main()
{
    int mycount = 1;
    int n;

    while (cin >> n) {
        if (n == 0)
            return 0;

        edges.clear();

        for (int i=0; i < n; ++i) {
            cin >> arr[i].x;
            cin >> arr[i].y;
        }

        edge e;
        for (int i=0; i < n; ++i) {
            for (int j=i+1; j < n; ++j) {
                double x0 = arr[i].x;
                double x1 = arr[j].x;

                double y0 = arr[i].y;
                double y1 = arr[j].y;

                double x_euclid = x1-x0;
                double y_euclid = y1-y0;

                x_euclid = x_euclid * x_euclid;
                y_euclid = y_euclid * y_euclid;

                double res = sqrt( x_euclid + y_euclid );
                e.x = i;
                e.y = j;
                e.z = res;
                edges.push_back(e);
            }
        }

        memset(ranks, 0, sizeof ranks);

        for (int i=0; i < n+4; ++i) {
            father[i] = i;
        }

        sort(edges.begin(), edges.end(), myfunc);
        int mysize = edges.size();

        vector<edge> mst;
        for (int i=0; i < mysize; ++i) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);
                mst.push_back(edges[i]);
                if (union_find(0) == union_find(1)) {
                    break;
                }
            }
        }
        //
        // printf("mst:\n");
        // for (auto it : mst) {
        //     printf("[%d][%d] => %f\n", it.x, it.y, it.z);
        // }

        double mymax = 0;
        for (auto it : mst) {
            mymax = max(mymax, it.z); 
        }

        printf("Scenario #%d\n", mycount);
        printf("Frog Distance = %.3f\n", mymax);
        printf("\n");
        mycount++;
    }
    return 0;
}
