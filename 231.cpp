#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
int n;

int main()
{
    int aux;
    vector<int> v;
    int counter = 0;
    bool last = false;
    while (scanf("%d", &aux) == 1) {
        if (aux == -1 && last == true)
            return 0;
        if (aux == -1) {

            vector<int> lis(v.size());

            int n = v.size();
            FOR(i, 0, n) {
                lis[i] = 1;
            }

            int ans = 1;
            FOR(i, 1, n) {
                FOR(j, 0, i) {
                    if (v[i] <= v[j]) {
                        lis[i] = max(lis[i], lis[j]+1);
                        ans = max(ans, lis[i]);
                    }
                }
            }

            if (counter)
                printf("\n");
            counter++;
            printf("Test #%d:\n", counter);
            printf("  maximum possible interceptions: %d\n", ans);
            last = true;
            v.clear();
        } else {
            v.push_back(aux);
            last = false;
        }
    }
    return 0;
}
