#include <bits/stdc++.h>

using namespace std;

map<string, string> mymap;

int main()
{
        string mystring, s1, s2;
        while (getline(cin, mystring)) {
                if (mystring.empty()) {
                        break;
                } else {
                        istringstream iss(mystring);
                        iss >> s1 >> s2;
                        mymap.emplace(s2, s1);
                }
        }

        while (cin >> mystring) {
                if (mymap.find(mystring) != mymap.end()) {
                        cout << mymap[mystring] << "\n";
                } else {
                        cout << "eh\n";
                }
        }

        return 0;
}
