#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
int arr[3010];
bool correct[3010];

int main()
{
        ios::sync_with_stdio(false);
        int n;
        while (cin >> n) {
                FOR(i, 0, n) {
                        cin >> arr[i];
                }

                int init = n-1;
                memset(correct, false, sizeof correct);
                bool possible = true;

                FOR(i, 0, n-1) {
                        int val = abs(arr[i] - arr[i+1]);
                        correct[val] = true;
                }

                FOR(i, 1, n) {
                        if (not correct[i]) {
                                possible = false;
                                break;
                        }
                }

                if (possible)
                        cout <<"Jolly\n";
                else
                        cout << "Not jolly\n";

        }
        return 0;
}
