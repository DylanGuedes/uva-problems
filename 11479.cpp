#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

using ll = long long;

int main()
{
        ios::sync_with_stdio(false);
        int t;
        cin >> t;
        repi(z, 0, t) {
                ll a, b, c;
                cin >> a >> b >> c;
                cout << "Case " << z+1 << ": ";
                if (a+b <= c || a+c <= b || b+c <= a)
                        cout << "Invalid\n";
                else {
                        if (a==b && b==c && c==a)
                                cout << "Equilateral\n";
                        else if ((a==b && a!= c) || (a==c && a!=b) || (b==c && b!=a))
                                cout << "Isosceles\n";
                        else if (a!=b && b!=c && c!=a) {
                                cout << "Scalene\n";
                        } else {
                                cout << "Invalid\n";
                        }
                }
        }
        return 0;
}
