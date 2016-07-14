#include <iostream>
#include <cstring>

using namespace std;

#define FOR(i,j,k)for(int i=j;i<k;++i)

int dp[1010][60];
int n, max_weight;
int w[1010];
int p[1010];

// int solve(int idx, int act_weight, int act_price)
// {
//     if (idx == n) {
//         return act_price;
//     }
//
//     if (dp[idx][act_weight] != -1)
//         return dp[idx][act_weight];
//
//     int ans = solve(idx+1, act_weight, act_price);
//     if (act_weight+w[idx] <= max_weight) {
//         ans = max(ans, solve(idx+1, act_weight+w[idx], act_price+p[idx]));
//     }
//     dp[idx][act_weight] = ans;
//     return dp[idx][act_weight];
// }

int solve(int idx, int remaining)
{
    if (idx == n)
        return 0;
    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];
    int ans = solve(idx+1, remaining);
    if (remaining-w[idx] >= 0)
        ans = max(ans, solve(idx+1, remaining-w[idx])+p[idx]);

    return dp[idx][remaining] = ans;
}

int main()
{
    int t, g;
    cin >> t;
    while(t--) {
        cin >> n;
        FOR(i,0,n) {
            cin >> p[i] >> w[i];
        }

        cin >> g;
        int total = 0;
        FOR(j,0,g) {
            cin >> max_weight;
            memset(dp, -1, sizeof dp);
            // int ans = solve(0,0,0);
            int ans = solve(0, max_weight);
            total += ans;
        }
        printf("%d\n", total);
    }
    return 0;
}
