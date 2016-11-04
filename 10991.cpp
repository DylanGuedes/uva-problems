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

                auto a=r1+r2;
                auto b=r2+r3;
                auto c=r1+r3;
                auto s=(a+b+c)/2;
                auto area=sqrt(s*(s-a)*(s-b)*(s-c));

                auto AB = acos((c*c - a*a - b*b)/(-2*a*b));
                auto AC = acos((b*b - a*a - c*c)/(-2*a*c));
                auto BC = acos((a*a - b*b - c*c)/(-2*b*c));

                area-=(AB*r2*r2)/2;
                area-=(BC*r3*r3)/2;
                area-=(AC*r1*r1)/2;

                cout << fixed << setprecision(6) << area << "\n";
        }
        return 0;
}
