#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int ranks[30];
int father[30];

int char_to_int(char x)
{
    return x-(65)+1;
}

int union_find(int x)
{
    if (father[x] == x)
        return x;
    else
        return union_find(father[x]);
}

void connect(int n1, int n2)
{
    int root1 = union_find(n1);
    int root2 = union_find(n2);

    if (ranks[root1] >= ranks[root2]) {
        ranks[root1]++;
        father[root2] = root1;
    } else {
        ranks[root2]++;
        father[root1] = root2;
    }
}

int main()
{
    int n;
    char init;
    char l1, l2;
    int t;
    cin >> t;

    for (int zz=0;zz<t; ++zz) {
        memset(ranks, 0, sizeof ranks);

        for (int i=0; i < 30; ++i) {
            father[i] = i;
        }

        cin >> init;
        n = char_to_int(init);
        while (cin >> l1 >> l2) {
            connect(char_to_int(l1)-1, char_to_int(l2)-1);
        }

        set<int> myset;
        for (int i=0; i < n; ++i) {
            myset.insert(father[i]);
        }
        cout << myset.size() << endl;
    }
    return 0;
}
