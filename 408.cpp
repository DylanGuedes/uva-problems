#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

vector<int> arr;

int main()
{
    int n;
    int aux;
    while (scanf("%d", &aux) == 1) {
        arr.push_back(aux);
    }

    vector<int> lis(arr.size() + 1);
    vector<int> parent(arr.size());
    n = arr.size();

    FOR(i, 0, n) {
        lis[i] = 1;
        parent[i] = i;
    }

    int lis_length = 0;
    int lis_idx = 0;
    FOR(i, 1, n) {
        FOR(j, 0, i) {
            if (arr[j] < arr[i]) {
                parent[j] = i;
                lis[i] = max(lis[i], lis[j]+1);
                if (lis_length < lis[i]) {
                    lis_idx = i;
                    lis_length = lis[i];
                }
            }
        }
    }
    printf("%d\n", lis_length);
    printf("-\n");
    printf("lis_idx:  %d\n", lis_idx);
    FOR(i, 0, n) {
        printf("%d: %d\n", i, parent[i]);
    }
    for (int i=lis_idx; i>=0; i--) {
        if (parent[i] == lis_idx)
            printf("%d\n", arr[i]);
    }
    return 0;
}
