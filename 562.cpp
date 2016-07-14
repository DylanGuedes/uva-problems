#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int m;
int coin[110];
long long int dp[110][26000];
long long int total;
#define FOR(i,j,k)for(int i=j;i<k;++i)

long long int solve(int idx, int perA, int perB)
{
    if (idx == m)
        return abs(perA-perB);

    if (dp[idx][abs(perA-perB)] != -1)
        return dp[idx][abs(perA-perB)];

    int sol = 0xffffff;
    if (perB <= total/2 && perA <= total/2) {
        sol = min(solve(idx+1, perA, perB+coin[idx]), solve(idx+1, perA+coin[idx], perB));
    } else if (perB <= total/2) {
        sol = solve(idx+1, perA, perB+coin[idx]);
    } else if (perA <= total/2) {
        sol = solve(idx+1, perA+coin[idx], perB);
    }

    dp[idx][abs(perA-perB)] = sol;
    return dp[idx][abs(perA-perB)];
}

int main()
{
    int n;
    cin >> n;
    FOR(z, 0, n) {
        cin >> m;
        total = 0;
        FOR(i, 0, m) {
            cin >> coin[i];
            total += coin[i];
        }
        memset(dp, -1, sizeof dp);
        long long int ans = solve(0, 0, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
