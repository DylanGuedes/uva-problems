#include <bits/stdc++.h>

using namespace std;

string row[210];
int visited[210][210];
using ii = pair<int, int>;
int n;

#define FOR(i, j, k)for(int i=j;i<k;++i)

#define x first
#define y second

void bfs(int fx, int fy)
{
        queue<ii> myq;
        myq.push(make_pair(fx, fy));
        visited[fy][fx] = 1;
        while (not myq.empty()) {
                ii pos = myq.front(); myq.pop();
                visited[pos.y][pos.x] = 1;
                vector<ii> myv {ii(pos.x-1, pos.y-1), ii(pos.x-1, pos.y), ii(pos.x, pos.y-1), ii(pos.x, pos.y+1), ii(pos.x+1, pos.y), ii(pos.x+1, pos.y+1)};
                for (auto it : myv) {
                        if (it.x < 0 || it.y < 0 || it.x >= n || it.y >= n) {
                                continue;
                        }
                        if (row[it.y][it.x] == 'b')
                                continue;
                        if (visited[it.y][it.x])
                                continue;
                        visited[it.y][it.x] = 1;
                        myq.push(ii(it.x, it.y));
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int counter = 1;
        while (cin >> n) {
                if (!n)
                        return 0;
                FOR(i, 0, n) {
                        cin >> row[i];
                }

                memset(visited, 0, sizeof visited);

                FOR(i, 0, n) {
                        if (row[i][0] == 'w' && not visited[i][0]) {
                                bfs(0, i);
                        }
                }
                bool white = false;

                FOR(i, 0, n) {
                        if (visited[i][n-1]) {
                                white = true;
                                break;
                        }
                }

                cout << counter << " ";
                if (white)
                        cout << "W\n";
                else
                        cout << "B\n";
                counter++;
        }

        return 0;
}
