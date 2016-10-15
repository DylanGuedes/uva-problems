#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
#define pb(i) push_back(i)
double const PI = 3.141592653589793;
double const EPS = 1e-12;

double equals(double a1, double a2)
{
        return fabs(a1-a2) < EPS;
}

class Triangle {
public:
        double a, b, c;
        Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) { }
        Triangle() { }

        typedef enum { RIGHT, ACUTE, OBTUSE } Angles;

        Angles classification_by_angles() const
        {
                auto AB = acos((c*c - a*a - b*b)/(-2*a*b));
                auto AC = acos((b*b - a*a - c*c)/(-2*a*c));
                auto BC = acos((a*a - b*b - c*c)/(-2*b*c));

                auto right = PI / 2.0;

                if (equals(AB, right) || equals(AC, right) || equals(BC, right))
                        return RIGHT;

                if (AB > right || AC > right || BC > right)
                        return OBTUSE;

                return ACUTE;
        }
        double area() const
        {
                auto s = perimeter() / 2.0;

                return sqrt(s)*sqrt(s-a)*sqrt(s-b)*sqrt(s-c);
        }

        double perimeter() const
        {
                return a+b+c;
        }

        double circumradius() const
        {

                return (a*b*c)/(4*area());
        }
};

double hole[110];

int main()
{
        ios::sync_with_stdio(false);
        int m;
        cin >> m;
        repi(i, 0, m)
                cin >> hole[i];
        int n;
        cin >> n;
        double a, b, c;
        vector<int> ans;
        repi(i, 0, n) {
                cin >> a >> b >> c;
                Triangle t(a, b, c);
                ans.clear();
                repi(j, 0, m) {
                        if (t.classification_by_angles() == Triangle::Angles::OBTUSE) {
                                double l_side = max(t.a, max(t.b, t.c));
                                if (hole[j] >= l_side)
                                        ans.pb(j+1);
                        } else {
                                if (t.circumradius() < (hole[j]/2.0) || equals(t.circumradius(), hole[j]/2.0))
                                        ans.pb(j+1);
                        }
                }

                cout << "Peg " << (char)('A'+i);
                if (ans.empty()) {
                        cout << " will not fit into any holes\n";
                } else {
                        cout << " will fit into hole(s):";
                        for (auto it : ans)
                                cout << " " << it;
                        cout << "\n";
                }
        }
        return 0;
}
