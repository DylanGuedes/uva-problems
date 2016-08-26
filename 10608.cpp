#include <iostream>
#include <cstring>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int ranks[30010];
int father[30010];

int union_find(int x)
{
    if (x == father[x])
        return x;
    else
        return father[x] = union_find(father[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);
    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]+=ranks[rooty]+1;
        father[rooty] = rootx;
    } else {
        ranks[rooty]+=ranks[rootx]+1;
        father[rootx] = rooty;
    }
}

int main()
{
    int origin, destination;
    int t, n, m;
    scanf("%d", &t);
    FOR(z, 0, t) {

        scanf("%d", &n);
        scanf("%d", &m);

        memset(ranks, 0, sizeof ranks);
        FOR(i, 0, n+2) {
            father[i] = i;
        }

        FOR(i, 0, m) {
            scanf("%d%d", &origin, &destination);
            if (union_find(origin) != union_find(destination)) {
                make_union(origin, destination);
            }
        }

        int mymax = -0xffffff;
        FOR(i, 1, n+1) {
            mymax = max(mymax, ranks[i]);
        }

        if (mymax == 0)
            mymax = -1;
        printf("%lld\n", mymax+1);

    }
    return 0;
}
