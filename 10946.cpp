#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
int height, width;

char arr[52][52];
bool visited[52][52];

using ii = pair<int, int>;

vector<pair<char, int> > dict;

int dfs(int x, int y, char l)
{
        visited[y][x] = 1;
        int s = 1;
        vector<ii> myv {ii(x+1, y), ii(x, y+1), ii(x-1, y), ii(x, y-1) };
        for (auto it : myv) {
                if (it.second < 0 || it.first < 0 || it.second >= height || it.first >= width)
                        continue;
                if (visited[it.second][it.first])
                        continue;
                if (arr[it.second][it.first] != l)
                        continue;
                s += dfs(it.first, it.second, l);
        }
        return s;
}

using ci = pair<char, int>;
bool myfunc(ci p1, ci p2)
{
        if (p1.second == p2.second)
                return p1.first < p2.first;
        else
                return p1.second > p2.second;
}

int main()
{
        ios::sync_with_stdio(false);
        int counter = 0;
        while (cin >> height >> width) {
                if(not(height | width))
                        return 0;
                dict.clear();
                FOR(i, 0, height) {
                        FOR(j, 0, width) {
                                cin >> arr[i][j];
                        }
                }
                memset(visited, 0, sizeof visited);

                FOR(i, 0, height) {
                        FOR(j, 0, width) {
                                if (not visited[i][j] && arr[i][j] != '.') {
                                        int val = dfs(j, i, arr[i][j]);
                                        dict.emplace_back(arr[i][j], val);
                                }
                        }
                }

                sort(dict.begin(), dict.end(), myfunc);
                cout << "Problem " << counter+1 << ":\n";
                for (auto it : dict) {
                        cout << it.first << " " << it.second << "\n";
                }
                counter++;
        }
        return 0;
}
