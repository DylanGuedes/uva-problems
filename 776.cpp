#include <bits/stdc++.h>

using namespace std;

string grid[200];
int visited[200][200];

#define FOR(i, j, k)for(int i=j;i<k;++i)

using ii = pair<int, int>;

map<char, int> mymap;

void solve(int n)
{
        memset(visited, 0, sizeof visited);
        int line_size = grid[0].size();
        int ptr = 1;
        FOR(i, 0, n) {
                FOR(j, 0, line_size) {
                        if (j)
                                cout << " ";
                        if (mymap.find(grid[i][j]) == mymap.end()) {
                                mymap.emplace(grid[i][j], ptr);
                                cout << setw(4) << mymap[grid[i][j]];
                                ptr++;
                        } else {
                                cout << setw(4) << mymap[grid[i][j]];
                        }
                }
                cout << "\n";
        }
        cout << "%\n";
}

int main()
{
        ios::sync_with_stdio(false);
        string mystring;
        int line = 0;
        int n = 1;
        n = 0;
        mymap.clear();
        while (getline(cin, mystring)) {
                if (mystring == "%") {
                        solve(n);
                        mymap.clear();
                        line = 0;
                        n = 0;
                } else {
                        istringstream iss(mystring);
                        char aux;
                        grid[line].clear();
                        while (iss >> aux) {
                                grid[line].push_back(aux);
                        }
                        n++;
                        line++;
                }
        }

        solve(n);
        return 0;
}
