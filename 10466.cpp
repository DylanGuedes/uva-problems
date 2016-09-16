#include <iostream>
#include <cmath>

#define FOR(i, j, k)for(int i=j;i<k;++i)

using namespace std;

#define pi 3.141592653589793

int t[55];
int r[55];
double dist[55];
using dd = pair<double, double>;
dd pos[55];

int main()
{
    int n, T;
    while (scanf("%d%d", &n, &T)==2) {
        FOR(i, 0, n) {
            scanf("%d%d", &r[i], &t[i]);
        }

        dist[0] = r[0];
        FOR(i, 0, n) {
            double ang = 2.0*pi*(double)T/t[i];
            pos[i].first = r[i]*cos(ang);
            pos[i].second = r[i]*sin(ang);

            if (i) {
                pos[i].first += pos[i-1].first;
                pos[i].second += pos[i-1].second;
#define x first
#define y second
                dist[i] = sqrt(pos[i].x*pos[i].x + pos[i].y*pos[i].y);
            }
            // printf("T: %d, t[i]: %d\n", T, t[i]);
            // printf("ang: %f\n", ang);
            // printf("sin(ang) = %f\n", sin(ang));
            // printf("i: %d, x: %f, y: %f, dist[%d] = %f\n", i, x, y, i, dist[i]);
        }

        FOR(i, 0, n) {
            if (i)
                printf(" ");
            printf("%.4lf", dist[i]);
        }
        printf("\n");
    }
    return 0;
}
