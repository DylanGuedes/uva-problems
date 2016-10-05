#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
double const EPS = 1e-9;

double equals(double a1, double a2)
{
        return fabs(a1-a2) < EPS;
}

class Triangle {
public:
        double a, b, c;
        Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) { }
        Triangle() { }

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
        repi(i, 0, n) {
                cin >> a >> b >> c;
                Triangle t(a, b, c);
                vector<int> ans;
                repi(j, 0, m) {
                        if (t.circumradius() < (hole[j]/2.0) || equals(t.circumradius(), hole[j]/2.0))
                                ans.push_back(j+1);
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
