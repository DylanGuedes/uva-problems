#include <iostream>
#include <cmath>

using namespace std;

int arr[5050][3];
int dist[5050];

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    int ptr = 0;
    while (cin >> arr[ptr][0] >> arr[ptr][1] >> arr[ptr][2]) {
        if (not(arr[ptr][0] | arr[ptr][1] | arr[ptr][2]))
            break;
        ptr++;
    }

    FOR(i, 0, ptr) {
        double part = 1000000000.0;
        FOR(j, 0, ptr) {
            if (i==j) continue;
            double xf = arr[j][0]-arr[i][0];
            double yf = arr[j][1]-arr[i][1];
            double zf = arr[j][2]-arr[i][2];
            part = min(part, sqrt(xf*xf + yf*yf + zf*zf));
        }
        dist[(int)part]++;
    }
    FOR(i,0,10)
        printf("%4d", dist[i]);
    printf("\n");
    return 0;
}
