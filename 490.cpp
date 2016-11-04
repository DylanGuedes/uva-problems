#include <bits/stdc++.h>

using namespace std;

class pt {
public:
        int x, y;
        pt(int _x, int _y):x(_x),y(_y) { }
        pt() { }
};
#define rep(i, j, k)for(int i=j;i<k;++i)

using interval = pair<double, double>;
int t;

class rect {
public:
        pt P, Q;
        double b, h;

        rect() { }

        rect(pt p1, pt p2):P(p1),Q(p2) {
                b = fabs(P.x - Q.x);
                h = fabs(P.y - Q.y);
        }

        bool intersection(const rect& r, rect& inter) const
        {
                auto I = interval(min(P.x, Q.x), max(P.x, Q.x));
                auto U = interval(min(r.P.x, r.Q.x), max(r.P.x, r.Q.x));

                auto a = max(I.first, U.first);
                auto b = min(I.second, U.second);

                if (b < a)
                        return false;

                I = interval(min(P.y, Q.y), max(P.y, Q.y));
                U = interval(min(r.P.y, r.Q.y), max(r.P.y, r.Q.y));

                auto c = max(I.first, U.first);
                auto d = min(I.second, U.second);

                if (d < c)
                        return false;

                inter = rect(pt(a, c), pt(b, d));

                return true;
        }

        double area() const
        {
                return b * h;
        }
};

int main()
{
        ios::sync_with_stdio(false);
        cin >> t;
        int xll, yll, xur, yur;
        rep(z, 0, t) {
                if (z)
                        cout << "\n";
                // cout << "z: " << z << "\n";
                cin >> xll >> yll >> xur >> yur;
                rect rect1(pt(xll, yll), pt(xur, yur));
                cin >> xll >> yll >> xur >> yur;
                rect rect2(pt(xll, yll), pt(xur, yur));
                rect result;
                if (rect1.intersection(rect2, result) && result.area()>0) {
                        cout << result.P.x << " " << result.P.y << " " << result.Q.x << " " << result.Q.y << "\n";
                } else {
                        cout << "No Overlap\n";
                }
        }
        return 0;
}
