#include <iostream>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int dist[110][110];

int main()
{
    int t, n, r, origin, destination;
    scanf("%d", &t);
    FOR(z, 0, t) {
        scanf("%d", &n);
        scanf("%d", &r);
        memset(dist, 0xF, sizeof dist);
        FOR(i, 0, r){
            scanf("%d", &origin);
            scanf("%d", &destination);
            dist[origin][destination] = 1;
            dist[destination][origin] = 1;
        }

        FOR(k, 0, n)
            FOR(i, 0, n)
                FOR(j, 0, n)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

        int total = 0;
        scanf("%d", &origin);
        scanf("%d", &destination);
        printf("%d\n", dist[origin][destination]);
    }

    return 0;
}
