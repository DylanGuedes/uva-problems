#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)

int main()
{
        ios::sync_with_stdio(false);
        int a[3];
        while (cin >> a[0] >> a[1] >> a[2]) {
                if ((a[0]+a[1]+a[2]) == 0)
                        return 0;
                sort(a, a+3);
                double theta1 = asin((double)a[1]/a[2]);
                double theta2 = asin((double)a[0]/a[2]);
                if (theta1 > theta2)
                        cout << "right\n";
                else
                        cout << "wrong\n";
        }
        return 0;
}
