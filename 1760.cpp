#include <iostream>
#include <cstring>

using namespace std;

int n;
int dp[110][12010];
int p[110];
int f[110];
int m;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int knapsack(int idx, int budget)
{
    if (budget > m && m < 1800)
        return -0xffffff;

    if (budget > m+200)
        return -0xffffff;

    if (idx == n) {
        if (budget > m && budget <= 2000)
            return -0xffffff;
        return 0;
    }

    if (dp[idx][budget] != -1)
        return dp[idx][budget];

    return dp[idx][budget] = max(knapsack(idx+1, budget), knapsack(idx+1, budget+p[idx]) + f[idx]);
}

int main()
{
    while (cin >> m >> n) {
        FOR(i, 0, n) {
            scanf("%d", &p[i]);
            scanf("%d", &f[i]);
        }
        memset(dp, -1, sizeof dp);
        printf("%d\n", knapsack(0, 0));
    }
    return 0;
}
