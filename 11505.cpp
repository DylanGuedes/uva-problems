#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)
#define pi acos(-1.0)

int main()
{
        int t, n;
        string command;
        int len;
        double x, y, dx, dy, theta;
        scanf("%d", &t);
        while(t--) {
                scanf("%d", &n);
                x = 0;
                y = 0;
                theta = 0;
                FOR(i, 0, n) {
                        dy = sin(theta);
                        dx = cos(theta);
                        cin >> command;
                        scanf("%d", &len);
                        if (command == "fd") {
                                x += dx*len;
                                y += dy*len;
                        } else if (command == "lt") {
                                theta += 2.0*pi*(double)len/360.0;
                                theta = fmod(theta, 360);
                        } else if (command == "rt") {
                                theta -= 2.0*pi*(double)len/360.0;
                                theta = fmod(theta, 360);
                        } else if (command == "bk") {
                                x -= dx*len;
                                y -= dy*len;
                        }
                }

                printf("%.0lf\n", sqrt(x*x+y*y));
        }
        return 0;
}
