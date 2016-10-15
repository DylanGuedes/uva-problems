#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
double const pi = 2*acos(0);
double const eps = 1e-10;
#define pb push_back

double equals(double a1, double a2)
{
        return fabs(a1-a2) < eps;
}

int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin >> n;
        string mystring;
        getline(cin, mystring);
        while(n--) {
                getline(cin, mystring);
                istringstream iss(mystring);
                int aux;
                vector<int> myv;
                while(iss >> aux) { myv.pb(aux); }

                if (myv.size() == 2) {
                        auto r1 = myv[0];
                        auto r2 = myv[1];
                        auto r3 = ((2*r1)+(2*r2))/2;
                        cout << fixed <<setprecision(4) << pi*r3*r3-(pi*r1*r1 + pi*r2*r2) << "\n";
                } else {
                        double t = myv[0];
                        double r = t/2;
                        double area1 = pi*r*r;
                        double r2 = r/2;
                        double area2 = r2*r2*pi;
                        cout << fixed <<setprecision(4) << area1-2*area2 << "\n";
                }
        }
        return 0;
}
