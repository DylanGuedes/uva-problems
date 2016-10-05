#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
int main()
{
        ios::sync_with_stdio(false);
        int n, m;
        while (cin >> n >> m) {
                if (not(n|m))
                        return 0;
                int num;
                multiset<int> s1, s2;
                repi(i, 0, n) {
                        cin >> num;
                        s1.insert(num);
                }
                repi(i, 0, m) {
                        cin >> num;
                        s2.insert(num);
                }
                int total = 0;
                for (auto it : s2) {
                        if (s1.count(it) > 0)
                                total++;
                }
                cout << total << "\n";
        }
        return 0;
}
