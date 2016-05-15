#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int x;
    int y;
    int z;
};

int ranks[1000020];
int father[1000020];
vector<edge> edges;

bool myfunc(edge e1, edge e2)
{
    return e1.z < e2.z;
}

int union_find(int x)
{
    if (x == father[x])
        return x;
    else
        return union_find(father[x]);
}

void make_union(int x, int y)
{
    int rootx = union_find(x);
    int rooty = union_find(y);

    if (ranks[rootx] > ranks[rooty]) {
        ranks[rootx]++;
        father[rooty] = rootx;
    } else {
        ranks[rooty]++;
        father[rootx] = rooty;
    }
}

int main()
{
    int n, origin, destiny, weight;
    int k;
    edge e;
    int counter = 0;
    while (cin >> n) {
        edges.clear();
        if (counter)
            printf("\n");
        int total_ed = 0;
        int m_value = 0;
        for (int i=0; i < n-1; ++i) {
            cin >> origin >> destiny >> weight;
            e.x = origin-1;
            e.y = destiny-1;
            e.z = weight;
            edges.push_back(e);
            m_value += weight;
        }

        for (int i=0; i < n+1; ++i) {
            father[i] = i;
        }

        memset(ranks, 0, sizeof ranks);

        cin >> k;
        for (int i=0; i < k; ++i) {
            cin >> origin >> destiny >> weight;
            e.x = origin-1;
            e.y = destiny-1;
            e.z = weight;
            edges.push_back(e);
        }
        
        
        sort(edges.begin(), edges.end(), myfunc);

        total_ed = edges.size();
        int new_cost = 0;

        for (int i=0; i < total_ed; ++i) {
            if (union_find(edges[i].x) != union_find(edges[i].y)) {
                make_union(edges[i].x, edges[i].y);
                new_cost += edges[i].z;
            }
        }

        cin >> k;
        for (int i=0; i < k; ++i) {
            cin >> origin >> destiny >> weight;
            e.x = origin-1;
            e.y = destiny-1;
            e.z = weight;
        }

        printf("%d\n", m_value);
        printf("%d\n", new_cost);
        counter++;
    }
    return 0;
}
