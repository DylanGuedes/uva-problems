#include <iostream>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
int arr[100020];

int main()
{
    int t, n;

    scanf("%d", &t);
    FOR(z, 0, t) {
        scanf("%d", &n);
        FOR(i, 0, n) {
            scanf("%d", &arr[i]);
        }
        int amount = 0;
        FOR(i, 1, n) {
            amount = max(amount+arr[i-1]-arr[i], arr[i-1]-arr[i]);
        }

        printf("%d\n", amount);
    }
}
