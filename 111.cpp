#include <iostream>
#include <cstring>

using namespace std;

#define FOR(i, j, k) for(int i=j;i<k;++i)
int A[23];
int arr[23];
int dp[23];

int main()
{
    int n, aux;
    cin >> n;
    FOR(i, 0, n) {
        scanf("%d", &arr[i]);
    }

    while (cin >> A[0]) {
        int lis = -0xfffff;
        memset(dp, -1, sizeof dp);
        FOR(i, 1, n) {
            scanf("%d", &A[i]);
        }
        dp[0] = 1;
        FOR(i, 1, n) {
            FOR(j, 0, i) {
                if (arr[j] < arr[i] && A[j] < A[i]) {
                    dp[i] = dp[j]+1;
                    lis = max(lis, dp[i]);
                } else if (arr[j] > arr[i] && A[j] > A[i]) {
                    dp[i] = dp[j]+1;
                    lis = max(lis, dp[i]);
                } else if (arr[j] == arr[i] && A[j] == A[i]) {
                    dp[i] = dp[j]+1;
                    lis = max(lis, dp[i]);
                } else {
                    dp[i] = dp[j];
                }
            }
        }
        if (lis < 0)
            lis = 1;
        printf("%d\n", lis);
    }
    return 0;
}
