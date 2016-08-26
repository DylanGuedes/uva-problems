#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>

using namespace std;

int d[25];
int dp[25][25];
int m;
int n;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int knapsack(int idx, int remaining)
{
    if (idx == m) {
        return 0;
    }

    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];

    printf("idx: %d, remaining: %d\n", idx, remaining);
    int ans = knapsack(idx+1, remaining);
    if (remaining >= d[idx]) {
        ans = max(ans, knapsack(idx+1, remaining-d[idx]) + 1);
    }

    return dp[idx][remaining] = ans;
}

int bfs()
{
    queue<pair<int, int> > myq;
    myq.push(make_pair(0, 0));
    bool visited[20][2000];
    memset(visited, false, sizeof visited);
    int maxdur = 0;
    while (not myq.empty()) {
        int idx = myq.front().second;
        int duration = myq.front().first;
        myq.pop();
        if (idx == m)
            continue;
        maxdur = max(maxdur, duration);
        if (not visited[idx+1][duration]) {
            visited[idx+1][duration] = true;
            myq.push(make_pair(duration, idx+1));
        }

        if ((duration + d[idx]) <= n) {
            if (not visited[idx+1][d[idx]+duration]) {
                visited[idx+1][d[idx]+duration] = true;
                myq.push(make_pair(d[idx]+duration, idx+1));
            }
        }
    }
    return maxdur;
}

int main()
{
    string mystring;
    while (getline(cin, mystring)) {
        istringstream iss(mystring);
        iss >> n;
        iss >> m;
        FOR(i, 0, m) {
            iss >> d[i];
        }
        memset(dp, -1, sizeof dp);
        printf("%d\n", bfs());
    }
    return 0;
}
