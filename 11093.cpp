#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int p[100005];
int q[100005];

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;

        FOR(z, 0, t) {
                int n;
                cin >> n;
                FOR(i, 0, n) {
                        cin >> p[i];
                }

                FOR(i, 0, n) {
                        cin >> q[i];
                }

                pair<int, int> highest = pair<int, int>(0, 0);
                bool possible = false;

                FOR(i, 0, n) {
                        int stop = i-1;

                        if (stop < 0) {
                                stop = n-1;
                        }

                        int ptr = i;
                        int val = p[ptr];
                        possible = true;

                        while (ptr != stop) {
                                val -= q[ptr];
                                if (val <= 0) {
                                        possible = false;
                                        break;
                                }
                                ptr = (ptr+1)%n;
                                val += p[ptr];
                        }

                        highest.first = i;
                        if (possible) {
                                break;
                        }
                }

                if (possible)
                        cout << "Case " << z+1 <<": Possible from station " << highest.first+1 << "\n";
                else
                        cout << "Case " << z+1 << ": Not possible\n";
        }

        return 0;
}
