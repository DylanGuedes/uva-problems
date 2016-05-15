#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge
{
    int x;
    int y;
    int z;
};

edge arr[2000050];
int ranks[2000050];
int father[2000050];

int union_find(int x)
{
    if (father[x] == x)
        return x;
    else
        return union_find(father[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);

    if (ranks[rootx] >= ranks[rooty]) {
        ranks[rootx]++;
        father[rooty] = rootx;
    } else {
        ranks[rooty]++;
        father[rootx] = rooty;
    }
}

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int main()
{
    int n, m, origin, destiny, weight;

    while (cin >> n >> m) {
        if (not (n | m))
            return 0;
        int total = 0;
        for (int i=0; i < m; ++i) {
            cin >> origin;
            cin >> destiny;
            cin >> weight;
            arr[i].x = origin;
            arr[i].y = destiny;
            arr[i].z = weight;
            total += weight;
        }

        memset(ranks, 0, sizeof ranks);
        for (int i=0; i < n; ++i) {
            father[i] = i;
        }

        sort(arr, arr+m, myfunc);

        int disc = 0;
        for (int i=0; i < m; ++i) {
            if (union_find(arr[i].x) != union_find(arr[i].y)) {
                make_union(arr[i].x, arr[i].y);
                disc += arr[i].z;
            }
        }

        cout << total - disc << endl;

    }
    return 0;
}

