#include <bits/stdc++.h>

using namespace std;

#define repi(i, j, k)for(int i=j;i<k;++i)
double const EPS = 1e-10;

int main()
{
        ios::sync_with_stdio(false);
        int n;
        while (cin >> n) {
                if (!n)
                        return 0;

                int highest_x=-1<<30, highest_y=-1<<30;
                int lowest_x=1<<30, lowest_y=1<<30;

                int myx, myy;
                repi(i, 0, n) {
                        cin >> myx >> myy;
                        highest_x=max(highest_x, myx);
                        lowest_x=min(lowest_x, myx);
                        highest_y=max(highest_y, myy);
                        lowest_y=min(lowest_y, myy);
                }

                double r;
                cin >> r;

                double median_y=(double)(abs(highest_y)+abs(lowest_y))/2;
                double median_x=(double)(abs(highest_x)+abs(lowest_x))/2;

                bool possible=false;
                if (r>=(median_y-EPS) && r>=(median_x-EPS))
                        possible=true;

                if (possible) {
                        cout << "The polygon can be packed in the circle.\n";
                } else {
                        cout << "There is no way of packing that polygon.\n";
                }
        }
        return 0;
}
