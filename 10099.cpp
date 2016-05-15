#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ZERO_TO(j) for(int i=0;i<j;++i)
#define ii pair<int, int>

struct edge
{
    int x;
    int y;
    int z;
};

vector<edge> edges;
int ranks[110];
int father[110];
vector<ii> mst[110];
int visited[110];

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

bool myfunc(edge e1, edge e2)
{
    return e1.z > e2.z;
}

int bfs(int origin, int destiny)
{
    memset(visited, 0, sizeof visited);
    queue<ii> myq;
    myq.push(ii(0xffffff, origin));
    while (not myq.empty()) {
        int idx = myq.front().second;
        int val = myq.front().first;
        visited[idx] = 1;
        myq.pop();

        if (idx == destiny) {
            return val;
        }

        for (auto it : mst[idx]) {
            if (visited[it.second] == 0) {
                myq.push(ii( min(it.first, val), it.second));
            }
        }
    }
}

int main()
{
    int n, m;
    edge e;
    int origin, destiny, weight;
    int mycounter = 1;

    while (cin >> n >> m) {
        if (not (n | m))
            return 0;

        edges.clear();
        ZERO_TO(m) {
            cin >> origin >> destiny >> weight;
            e.x = origin;
            e.y = destiny;
            e.z = weight;
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end(), myfunc);
        memset(ranks, 0, sizeof ranks);
        for (int i=0; i < n+2; ++i) {
            father[i] = i;
        }

        for (int i=0; i < n+2; ++i) {
            mst[i].clear();
        }

        ZERO_TO(m) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);

                mst[edges[i].x].push_back(ii(edges[i].z, edges[i].y));
                mst[edges[i].y].push_back(ii(edges[i].z, edges[i].x));
            }
        }

        cin >> origin >> destiny >> weight;

        for (int i=0; i < n+2; ++i) {
            father[i] = i;
        }

        int lower = bfs(origin, destiny);
        lower--;
        int ans = 0;
        while (weight > 0) {
            weight -= lower;
            ans++;
        }
        printf("Scenario #%d\n", mycounter);
        printf("Minimum Number of Trips = %d\n", ans);
        mycounter++;
        printf("\n");
    }

    return 0;
}
