#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

#define FOR(i,j,k)for(int i=j;i<k;++i)

vector<int> friends[30];
vector<int> rev_friends[30];
stack<int> mystack;
map<string, int> mymap;
map<int, string> revmap;
bool visited[30];
int n, m;
string origin, destination;

void dfs(int idx)
{
    visited[idx] = true;
    for (auto it : friends[idx]) {
        if (not visited[it]) {
            dfs(it);
        }
    }
    mystack.push(idx);
}

void dfs2(int idx)
{
    visited[idx] = true;
    printf("%s", revmap[idx].c_str());
    for (auto it : rev_friends[idx]) {
        if (visited[it] == false) {
            dfs2(it);
        }
    }
}

int main()
{
    int count;
    while (cin >> n >> m) {
        if (not (n|m))
            return 0;

        count = 0;
        FOR(i, 0, n+2) {
            friends[i].clear();
            rev_friends[i].clear();
        }

        mymap.clear();
        revmap.clear();
        while (not mystack.empty()) {
            mystack.pop();
        }

        memset(visited, false, sizeof visited);
        FOR(i, 0, m) {
            cin >> origin >> destination;
            if (mymap.find(origin) == mymap.end()) {
                mymap.insert(make_pair(origin, count));
                revmap.insert(make_pair(count, origin));
                count++;
            }
            if (mymap.find(destination) == mymap.end()) {
                mymap.insert(make_pair(destination, count));
                revmap.insert(make_pair(count, destination));
                count++;
            }

            friends[mymap[origin]].push_back(mymap[destination]);
            rev_friends[mymap[origin]].push_back(mymap[destination]);
        }

        FOR(i, 0, n) {
            if (not visited[i]) {
                dfs(0);
            }
        }

        memset(visited, false, sizeof visited);
        while (not mystack.empty()) {
            int idx = mystack.top(); mystack.pop();
            if (not visited[idx]) {
                dfs2(idx);
                printf("\n");
            }
            printf("fim do scc..\n");
        }
    }

    return 0;
}
