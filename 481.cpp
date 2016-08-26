#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int arr[100000];
int dp[100000];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    int counter = 0;
    while (scanf("%d", &arr[counter]) == 1)
        counter++;

    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    set<int> myset;
    FOR(i, 1, counter) {
        FOR(j, 0, i) {
            if (arr[j] <= arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                myset.insert(arr[j]);
            }
        }
    }
    printf("%d\n", myset.size());
    printf("-\n");
    for (auto it  : myset)
        printf("%d\n", it);


    return 0;
}
