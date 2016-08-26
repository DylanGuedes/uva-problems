#include <iostream>
#include <cstring>

using namespace std;

int n;
int dp[1010][6010];
int l[1010];
int w[1010];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int knapsack(int idx, int max_load)
{
    if (idx == n)
        return 0;

    if (dp[idx][max_load] != -1)
        return dp[idx][max_load];

    int ans = knapsack(idx+1, max_load);

    if (max_load >= w[idx]) {
        if (w[idx] <= max_load) {
            ans = max(ans, knapsack(idx+1, min(max_load-w[idx], l[idx])) + 1);
        }
    }

    return dp[idx][max_load] = ans;
}

int main()
{
    while (cin >> n) {
        if (not n)
            return 0;

        FOR(i, 0, n) {
            scanf("%d", &w[i]);
            scanf("%d", &l[i]);
        }

        memset(dp, -1, sizeof dp);
        printf("%d\n", knapsack(0, 6000));
    }
    return 0;
}
