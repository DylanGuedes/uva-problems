#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int parent[230];
int ranks[230];

map<string, int> mymap;

struct edge {
    int x, y, z;
};

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

vector<edge> edges;
vector<edge> mst;

int union_find(int x)
{
    if (x == parent[x])
        return x;
    else
        return union_find(parent[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);
    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        parent[rooty] = rootx;
    } else {
        ranks[rooty]++;
        parent[rootx] = rooty;
    }
}

int main()
{
    int n, r;
    string origin, destination;
    int weight;
    edge e;
    int last_item = 0;
    while (scanf("%d%d", &n, &r)) {
        mymap.clear();
        edges.clear();
        mst.clear();
        FOR(i, 0, r) {
            cin >> origin;
            cin >> destination;
            cin >> weight;
            if (mymap.find(origin) == mymap.end()) {
                mymap.emplace(origin, last_item);
                last_item++;
            }
            if (mymap.find(destination) == mymap.end()) {
                mymap.emplace(destination, last_item);
                last_item++;
            }
            e.x = mymap[origin];
            e.y = mymap[destination];
            e.z = weight;
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end(), myfunc);

        FOR(i, 0, n+4)
            parent[i] = i;

        memset(ranks, 0, sizeof ranks);

        int total_edges = edges.size();
        FOR(i, 0, total_edges) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);
                make_union(edges[i].x, edges[i].y);
                mst.push_back(edges[i]);
            }
        }
    }
    return 0;
}
