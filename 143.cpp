#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb(i) push_back(i)
#define eb(i, j) emplace_back(i, j)
double const eps = 1e-9;
using ii = pair<int, int>;

double equals(double a1, double a2)
{
        return fabs(a1-a2) < eps;
}

class point {
public:
        double x, y;
        point() { }
        point(double _x, double _y) : x(_x),y(_y) { }
};
using pp = pair<point, point>;

class segment {
public:
        point A, B;
        segment() { }
        segment(point p1, point p2) : A(p1),B(p2) { }
        bool contains(const point& P) const
        {
                if (min(A.x, B.x) <= P.x && max(A.x, B.x) >= P.x && min(A.y, B.y) <= P.y && max(A.y, B.y) >= P.y)
                        return true;
                return false;
        }
};

double D(const point& p, const point& Q, const point& R)
{
        return (p.x * Q.y + p.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * p.x + Q.x * p.y);
}

vector<int> signs;
vector<pair<pp, double> > ans;
#define mp(i, j) make_pair(i, j)

class triangle {
public:
        point p,q,r;
        triangle(point p1, point p2, point p3) : p(p1),q(p2),r(p3) { }

        bool inside(const point& w)
        {
                ans.clear();
                signs.clear();
                ans.eb(pp(p, q), D(p, q, w));
                ans.eb(pp(q, r), D(q, r, w));
                ans.eb(pp(r, p), D(r, p, w));
                for (auto it : ans) {
                        pp d;
                        double det;
                        tie(d, det) = it;
                        if (equals(det, 0)) {
                                segment s(d.first, d.second);
                                if (s.contains(w))
                                        return true;
                                else {
                                        signs.pb(-1);
                                }
                        } else {
                                if (det >= eps)
                                        signs.pb(1);
                                else
                                        signs.pb(0);
                        }
                }
                bool possible = true;
                repi(i, 1, 3) {
                        if (signs[i] == -1 || signs[i-1] == -1)
                                return false;
                        if (signs[i] != signs[i-1])
                                possible = false;
                }
                return possible;
        }
};


int main()
{
        ios::sync_with_stdio(false);
        point p, q, r;
        while (cin >> p.x >> p.y) {
                cin >> q.x >> q.y;
                cin >> r.x >> r.y;
                if (equals(p.x, 0) && equals(r.x, 0) && equals(q.x, 0) && equals(p.y, 0) && equals(r.y, 0) && equals(q.y, 0))
                        return 0;
                // double highest_x = max(max(p.x, q.x), r.x);
                // double highest_y = max(max(p.y, q.y), r.y);;
                // double lowest_x = min(min(p.x, q.x), r.x);
                // double lowest_y = min(min(p.y, q.y), r.y);
                triangle t(p, q, r);
                int total = 0;
                // lowest_y = max(lowest_y, 1.0);
                // lowest_x = max(lowest_x, 1.0);
                // highest_y = min(highest_y, 99.0);
                // highest_x = min(highest_x, 99.0);
                for (int i=1; i<=99; ++i) {
                        for (int j=1; j<=99; ++j) {
                                if (t.inside(point(j, i))) {
                                        // cout << "i: " << i << ", j: " << j << " dentro do triangulo.\n";
                                        total++;
                                }
                        }
                }
                cout << setw(4) << total << "\n";
        }
        return 0;
}
#define all(x) x.begin(),x.end()
