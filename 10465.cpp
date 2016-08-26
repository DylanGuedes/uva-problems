#include <iostream>
#include <cstring>

using namespace std;

int m, n, t;
int dp[10020];

#define FOR(i, j, k)for(int i=j;i<k;i++)

int solve(int idx)
{
    if (idx == t)
        return dp[idx] = 0;

    if (dp[idx] != -1)
        return dp[idx];

    int ans = 0;

    if (idx+m <= t)
        ans = max(ans, 1+solve(idx+m));
    if (idx+n <= t)
        ans = max(ans, 1+solve(idx+n));

    return dp[idx] = ans;
}

int main()
{
    while (cin >> n >> m >> t) {
        memset(dp, -1, sizeof dp);

        int ans = solve(0);
        if (dp[t] == -1) {
            for (int i=t;i>=0;i--) {
                if(dp[i] != -1) {
                    printf("%d %d\n", ans, t-i);
                    break;
                }
            }
        } else {
            printf("%d\n", ans);
        }

    }
    return 0;
}
