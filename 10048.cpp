#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, j, k) for(int i=j; i< k; ++i)
#define MEMSET(i) memset(i, 0, sizeof i);
#define ii pair<int, int>

struct edge
{
    int x;
    int y;
    int z;
};

vector<edge> edges;
vector<ii> graph[110];
int visited[110];

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int father[110];
int ranks[110];

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

void bfs(int origin, int destiny)
{
    MEMSET(visited);
    queue<ii> myq;
    myq.push(ii(0, origin));
    int mymax = 0;
    while (not myq.empty()) {
        int idx = myq.front().second;
        int val= myq.front().first;
        visited[idx] = 1;
        // printf("idx: %d\n", idx);
        myq.pop();
        if (idx == destiny) {
            mymax = max(mymax, val);
            break;
        }
        for (auto it : graph[idx]) {
            if (visited[it.second] == 0) {
                myq.push(ii( max(val, it.first), it.second));
            }
        }
    }

    if (mymax == 0)
        printf("no path\n");
    else
        printf("%d\n", mymax);
}

int main()
{
    int n, m, q;
    int counter = 0;
    int origin, destiny, weight;
    while (cin >> n >> m >> q) {
        if (not (n | m | q))
            return 0;

        if (counter)
            printf("\n");

        edges.clear();
        FOR(i, 0, n+2) {
            graph[i].clear();
        }
        edge e;

        FOR(i, 0, m) {
            cin >> origin >> destiny >> weight;
            e.x = origin-1;
            e.y = destiny-1;
            e.z = weight;
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end(), myfunc);

        MEMSET(ranks);
        int mysize = edges.size();
        FOR(i, 0, n+1) {
            father[i] = i;
        }
        FOR(i, 0, mysize) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);
                // printf("make_union between %d and %d\n", edges[i].x, edges[i].y);
                graph[edges[i].x].push_back(ii(edges[i].z, edges[i].y));
                graph[edges[i].y].push_back(ii(edges[i].z, edges[i].x));
            }
        }
        //
        // printf("mst:\n");
        // FOR(i, 0, n) {
        //     for (auto it : graph[i]) {
        //         printf("%d to %d => %d\n", i, it.second, it.first);
        //     }
        // }
        // printf("\n");

        printf("Case #%d\n", counter+1);

        FOR(i, 0, q) {
            cin >> origin >> destiny;
            bfs(origin-1, destiny-1);
        }

        counter++;
    }
    return 0;
}
