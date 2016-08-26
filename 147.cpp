#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

vector<int> cs{10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long int n;
long long int dp[13][30000];

long long int solve(int idx, long long int remaining)
{
    // printf("idx: %d, remaining: %lld\n", idx, remaining);
    if (remaining == 0)
        return 1;
    if (remaining < 0)
        return 0;
    if (idx >= 11) {
        return 0;
    }

    if (dp[idx][remaining] != -1)
        return dp[idx][remaining];

    long long int ans = solve(idx+1, remaining);
    if (remaining >= cs[idx])
        ans += solve(idx, remaining - cs[idx]);

    return dp[idx][remaining] = ans;
}

int main()
{
    double val;
    while (cin >> val) {
        if (val-0.0 < 0.00001)
            return 0;
        memset(dp, -1, sizeof dp);
        double aux = val*100.0;
        printf("%6.2f %16lld\n", val, solve(0, (long long int)round(aux)));
    }

    return 0;
}
