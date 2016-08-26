#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
#define mp make_pair
using ii = pair<int, int>;

int grid[1010][1010];
int m, n;

void dijkstra()
{
    priority_queue<pair<int, ii>, vector< pair<int, ii> >, greater<pair<int, ii> > > pq;
    pq.push(mp(grid[0][0], ii(0, 0)));
    vector<int> inf_vec(1010, 1<<30);
    vector<vector<int> > dist(1010, inf_vec);
    dist[0][0] = 0;
    while (not pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int val = pq.top().first;
        pq.pop();

        if (x==n-1 && y==m-1) {
            printf("%d\n", val);
            return;
        }

        vector<ii> myv {ii(x+1, y), ii(x-1, y), ii(x, y+1), ii(x, y-1) };
        for (auto it : myv) {
            if (it.first >= 0 && it.second >= 0 && it.first < n && it.second < m) {
                int ele = grid[it.second][it.first];
                if (ele+val < dist[it.second][it.first]) {
                    dist[it.second][it.first] = ele+val;
                    pq.push(mp(ele+val, it));
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    FOR(z, 0, t) {
        scanf("%d%d", &m, &n);
        FOR(i, 0, m) {
            FOR(j, 0, n) {
                scanf("%d", &grid[i][j]);
            }
        }

        dijkstra();
    }
    return 0;
}
