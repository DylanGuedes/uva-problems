#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        int g;
        int m;

        while (cin >> g) {
                if (not g)
                        return 0;
                string mystr;
                cin >> mystr;
                int len = mystr.size();
                auto it = mystr.begin();

                m = len/g;
                repi(i, 0, len) {
                        reverse(it, it+m);
                        int j = 0;
                        while (j != m && it != mystr.end()) {
                                j++;
                                it++;
                        }
                }
                cout << mystr << "\n";
        }
        return 0;
}
