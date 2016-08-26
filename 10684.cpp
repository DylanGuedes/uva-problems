#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int arr[10010];
int s[10010];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        if (not n)
            return 0;
        FOR(i, 0, n)
            scanf("%d", &arr[i]);
        s[0] = arr[0];
        int ans = -1;
        FOR(i, 1, n) {
            s[i] = max(arr[i], s[i-1]+arr[i]);
            ans = max(ans, s[i]);
        }

        if (ans <= 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", ans);
    }
    return 0;
}
