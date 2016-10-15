#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        int k;
        cin >> k;
        while(k--) {
                double r1, r2, r3;
                cin >> r1 >> r2 >> r3;
                if (r3 > r2)
                        swap(r3, r2);
                if (r1 < r2)
                        swap(r1, r2);
                if (r3 > r1)
                        swap(r3, r1);
                auto theta = asin(r2/(r1+r2));
                auto delta = acos(r2/(r2+r1));
                auto psi = acos(r3/(r3+r1));
                auto alpha = asin(r3/(r1+r3));
                auto h = (r2+r1)*sin(delta);
                auto a1 = (theta+alpha)*r1*r1/2;
                auto a2 = delta*r2*r2/2;
                auto a3 = psi*r3*r3/2;
                // cout << "a1: " << a1 << ", " << a2 << ", " << a3 << "\n";
                // cout << "H: " << h << "\n";

                cout << (r2+r3)*h/2.0 - (a1+a2+a3) << "\n";
        }
        return 0;
}
