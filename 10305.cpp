#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

vector<int> graph[110];
bool visited[110];
stack<int> mystack;

void dfs(int idx)
{
    visited[idx] = true;
    for (auto it : graph[idx]) {
        if (not visited[it])
            dfs(it);
    }
    mystack.push(idx);
}

int main()
{
    int origin, destination, n, m;
    while (cin >> n >> m) {
        if (not(n|m))
            return 0;

        FOR(i, 0, n+5)
            graph[i].clear();

        FOR(i, 0, m) {
            scanf("%d%d", &origin, &destination);
            graph[origin].push_back(destination);
        }

        memset(visited, 0, sizeof visited);
        FOR(i, 1, n+1) {
            if (not visited[i])
                dfs(i);
        }

        bool flag = false;
        while (not mystack.empty()) {
            if (flag)
                printf(" ");
            flag = true;
            printf("%d", mystack.top());
            mystack.pop();
        }
        printf("\n");
    }
    return 0;
}
