#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

vector<int> graph[30];
map<char, int> mymap;
int visited[30];

void dfs(int idx)
{
        visited[idx] = true;
        for (auto it : graph[idx])
                if (not visited[it])
                        dfs(it);
}

int main()
{
        int t;
        scanf("%d", &t);
        FOR(i, 0, 27) {
                mymap.emplace('A'+i, i);
        }
        FOR(z, 0, t) {
                FOR(i, 0, 30)
                        graph[i].clear();
                string mystring;
                char largest;
                cin >> largest;
                getline(cin, mystring);
                while (getline(cin, mystring)) {
                        if (mystring.size() < 1)
                                break;
                        graph[mymap[mystring[0]]].push_back(mymap[mystring[1]]);
                        graph[mymap[mystring[1]]].push_back(mymap[mystring[0]]);
                }

                memset(visited, 0, sizeof visited);
                int total = 0;

                FOR(i, 0, largest-'A'+1) {
                        if (not visited[i]) {
                                total++;
                                dfs(i);
                        }
                }
                if (z)
                        printf("\n");
                printf("%d\n", total);
        }
        return 0;
}
