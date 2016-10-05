#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int h, w;
int visited[100][100];
char grid[100][100];
using ii = pair<int, int>;
vector<pair<char, int> > dict;

void dfs(int x, int y, char target)
{
        visited[y][x] = 1;

        vector<ii> myv {ii(x+1, y), ii(x, y+1), ii(x, y-1), ii(x-1, y) };
        for (auto it : myv) {
                if (it.second < 0 || it.first < 0 || it.first >= w || it.second >= h)
                        continue;
                if (visited[it.second][it.first])
                        continue;
                if (grid[it.second][it.first] != target)
                        continue;
                dfs(it.first, it.second, target);
        }
}

bool has_lang(char lan)
{
        for (auto it : dict) {
                if (it.first == lan)
                        return true;
        }
        return false;
}

bool myfunc(pair<char, int> p1, pair<char, int> p2)
{
        if (p1.second == p2.second)
                return p1.first < p2.first;
        else {
                return p1.second > p2.second;
        }
}

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        FOR(z, 0, n) {
                dict.clear();
                cin >> h >> w;
                FOR(i, 0, h) {
                        FOR(j, 0, w) {
                                cin >> grid[i][j];
                        }
                }

                memset(visited, 0, sizeof visited);
                FOR(i, 0, h) {
                        FOR(j, 0, w) {
                                if (not visited[i][j]) {
                                        if (not has_lang(grid[i][j])) {
                                                dict.emplace_back(grid[i][j], 1);
                                        } else {
                                                for (auto &it : dict) {
                                                        if (it.first == grid[i][j])
                                                                it.second++;
                                                }
                                        }
                                        dfs(j, i, grid[i][j]);
                                }
                        }
                }
                sort(dict.begin(), dict.end(), myfunc);
                cout << "World #" << z+1 << "\n";
                for (auto it : dict) {
                        cout << it.first << ": " << it.second << "\n";
                }
        }
        return 0;
}
