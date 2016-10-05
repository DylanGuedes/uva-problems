#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int arr[110];

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        FOR(z, 0, t) {
                int n;
                cin >> n;
                int p;
                cin >> p;
                FOR(i, 0, p) {
                        cin >> arr[i];
                }
                int day_counter = 0;
                FOR(i, 1, n+1) {
                        FOR(j, 0, p) {
                                if ((i%arr[j]) == 0 && arr[j] <= i) {
                                        if ((i%7 != 6) && (i%7 != 0)) {
                                                day_counter++;
                                                break;
                                        }
                                }
                        }
                }

                cout << day_counter<< "\n";
        }
        return 0;
}
