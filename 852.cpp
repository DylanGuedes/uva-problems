#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

char grid[10][10];
int total_black;
int visited[11][11];
int total_white;

int line_size;
int n;

using ii = pair<int, int>;

void bfs(int x, int y, char forb)
{
        queue<ii> myq;
        myq.push(make_pair(x, y));
        while (not myq.empty()) {
                ii pos = myq.front(); myq.pop();
                visited[pos.second][pos.first] = 1;
                vector<ii> myv {
                        ii(pos.first+1, pos.second), ii(pos.first-1, pos.second),
                        ii(pos.first, pos.second+1), ii(pos.first, pos.second-1)
                };
                total_black++;
                total_white++;

                for (auto it : myv) {
                        if (it.first < 0 || it.second < 0 || it.first >= 9||  it.second >= 9) {
                                continue;
                        }
                        if (visited[it.second][it.first])
                                continue;
                        if (grid[it.second][it.first] == forb)
                                continue;
                        visited[it.second][it.first] = 1;
                        myq.push(it);
                }
        }
}

void solve()
{
        memset(visited, 0, sizeof visited);
        FOR(i, 0, 9) {
                FOR(j, 0, 9) {
                        if (not visited[i][j]) {
                                if (grid[i][j] == 'O') {
                                        bfs(j, i, 'X');
                                }
                        }
                }
        }
        total_black = 0;
        FOR(i, 0, 9) {
                FOR(j, 0, 9) {
                        if (not visited[i][j] && grid[i][j] == 'X') {
                                bfs(j, i, 'O');
                        }
                }
        }
        int ans_blac = total_black;

        memset(visited, 0, sizeof visited);
        FOR(i, 0, 9) {
                FOR(j, 0, 9) {
                        if (not visited[i][j]) {
                                if (grid[i][j] == 'X') {
                                        bfs(j, i, 'O');
                                }
                        }
                }
        }

        total_white = 0;
        FOR(i, 0, 9) {
                FOR(j, 0, 9) {
                        if (grid[i][j] == 'O' || grid[i][j] == '.') {
                                if (not visited[i][j] && grid[i][j] == 'O')
                                        bfs(j, i,'X');
                        }
                }
        }

        cout << "Black "<<  ans_blac << " White " << total_white << "\n";
}

int main()
{
        ios::sync_with_stdio(false);

        int t;
        cin >> t;
        while (t--) {
                FOR(i, 0, 9) {
                        FOR(j, 0, 9) {
                                cin >> grid[i][j];
                        }
                }
                solve();
        }
        return 0;
}
