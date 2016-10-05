#include <bits/stdc++.h>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        string mystring;
        while (cin >> mystring) {
                int aux = mystring[0] - 'a' + 1;
                int stringsize = mystring.size();
                bool possible = true;
                int total = 0;
                int pot = 1;
                for (int i=0; i < stringsize; ++i) {
                        if (not i)
                                continue;
                        if (mystring[i] <= aux) {
                                possible = false;
                                break;
                        }
                        aux = mystring[i] - 'a'+1;
                }

                if (possible)
                        cout << total << "\n";
                else
                        cout << 0 << "\n";
        }
        return 0;
}
