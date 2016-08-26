#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int arr[21000];
int dp[21000];

int main()
{
    int n, r;
    scanf("%d", &n);
    FOR(z, 0, n) {
        scanf("%d", &r);
        FOR(i, 1, r) {
            scanf("%d", &arr[i]);
        }
        dp[0] = max(arr[0], 0);
        int ans = -0xfffffff;
        int start_stop = 1;
        int final_stop = 1;
        int start_solution = 1;
        int partial_sum = 0;
        FOR(i, 1, r) {
            partial_sum += arr[i];
            if (partial_sum < 0) {
                start_stop = i+1;
                partial_sum = 0;
            }
            if (partial_sum > ans || (partial_sum == ans && i-start_stop>final_stop-start_solution)) {
                final_stop = i;
                ans = partial_sum;
                start_solution = start_stop;
            }
        }

        if (ans > 0) {
            printf("The nicest part of route %d is between stops %d and %d\n", z+1, start_solution, final_stop+1);
        } else {
            printf("Route %d has no nice parts\n", z+1);
        }

    }
    return 0;
}
