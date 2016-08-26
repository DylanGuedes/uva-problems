#include <iostream>

using namespace std;

int union_find(int x)
{
    if (x == father[x])
        return x;
    else
        return father[x] = union_find(father[x]);
}

int main()
{
    int t;
    scanf("%d", &t);
    FOR(z, 0, t) {
        string mystring;
        while (1) {
            getline(cin, mystring);
            if (mystring == "")
                break;

        }
    }

    return 0;
}
