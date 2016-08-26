#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
long long int dp[11000];
long long int arr[11000];

int main()
{
    int t;
    long long int a, b, c;
    scanf("%d", &t);
    long long int ans = -1<<31;
    FOR(z, 0, t) {
        scanf("%lld%lld%lld", &a, &b, &c);
        long long int n = a*b*c;
        scanf("%lld", &arr[0]);
        dp[0] = arr[0];
        ans = dp[0];
        FOR(i, 1, n) {
            scanf("%lld", &arr[i]);
            if (arr[i]>arr[i-1])
                dp[i] = max(arr[i], dp[i-1]+arr[i]);
            else
                dp[i] = arr[i];
            ans = max(ans, dp[i]);
        }
        if (z)
            printf("\n");
        cout << ans << endl;
    }
    return 0;
}
