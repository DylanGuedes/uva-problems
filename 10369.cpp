#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i, j, k) for (int i=j;i <k; ++i)
#define MEMSET(i) memset(i, 0, sizeof i)

struct edge
{
    int x, y;
    double z;
};

vector<edge> edges;
edge arr[550];
int ranks[550];
int father[550];

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

int main()
{
    int m, n;
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        FOR(i, 0, n) {
            cin >> arr[i].x;
            cin >> arr[i].y;
        }

        edges.clear();
        edge e;
        FOR(i, 0, n) {
            FOR(j, i+1, n) {
                double x0 = arr[i].x;
                double y0 = arr[i].y;

                double x1 = arr[j].x;
                double y1 = arr[j].y;

                double eucl_x = x1-x0;
                double eucl_y = y1-y0;

                eucl_x = eucl_x * eucl_x;
                eucl_y = eucl_y * eucl_y;
                
                double myresult = sqrt (eucl_x + eucl_y);

                e.x = i;
                e.y = j;
                e.z = myresult;

                edges.push_back(e);
            }
        }

        MEMSET(ranks);
        FOR(i, 0, n+3) {
            father[i] = i;
        }


        sort(edges.begin(), edges.end(), myfunc);
        int mysize = edges.size();
        vector<double> myresults;
        FOR(i, 0, mysize) {
            // printf("dentro do uf\n");
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                // printf("union_find\n");
                make_union(edges[i].x, edges[i].y);
                myresults.push_back(edges[i].z);
            }
        }

        // printf("MY RESULTS:\n");
        // FOR(i, 0, myresults.size()) {
        //     printf("%f\n", myresults[i]);
        // }

        sort(myresults.begin(), myresults.end(), greater<double>());
        // printf("MY RESULTS:\n");
        // FOR(i, 0, myresults.size()) {
        //     printf("%f\n", myresults[i]);
        // }
        printf("%.2f\n", myresults[m-1]);
    }
    return 0;
}
