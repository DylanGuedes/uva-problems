#include <bits/stdc++.h>

using namespace std;

#define rep(i, j, k)for(int i=j;i<k;++i)

class pt {
public:
        int x, y;
        pt(int _x, int _y):x(_x),y(_y) {}
        pt() { }
};

using interval = pair<double, double>;

class rect {
public:
        pt P, Q;
        double b, h;

        rect() { P=pt(0,0); Q=pt(0,0);}

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
        int t;
        cin >> t;
        rep(z, 0, t) {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                rect g1(pt(x1, y1), pt(x2, y2));
                cin >> x1 >> y1 >> x2 >> y2;
                rect g2(pt(x1, y1), pt(x2, y2));
                rect initial(pt(0, 0), pt(100, 100));
                rect g1andg2;
                rect strongarea;
                bool g1andg2intersect=g1.intersection(g2, g1andg2);
                bool strongintersect=g1andg2.intersection(initial, strongarea);
                cout << "Night " <<z+1<<": ";
                cout << strongarea.area() << " " << g1.area()+g2.area()-(2*strongarea.area()) << " " << initial.area()-(g1.area()+g2.area()-strongarea.area()) << "\n";
        }
}
