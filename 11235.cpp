#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int arr[100005];

int main()
{
        ios::sync_with_stdio(false);
        int n, q, left, right;
        while (cin >> n >> q) {
                if (n == 0)
                        return 0;
                FOR(i, 0, n) {
                        cin >> arr[i];
                }

                vector< vector<int> > s_table(n,vector<int>(log2(n)+1));

                FOR(i, 0, n) {
                        cout << "THATSIZE: " << s_table[i].size() << "\n";
                }

                FOR(i, 0, q) {
                        cin >> left >> right;
                }
        }

        return 0;
}
