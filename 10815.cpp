#include <bits/stdc++.h>

using namespace std;

#define pb(i) push_back(i)

bool in_range_1(char a)
{
        if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
                return true;
        return false;
}

int main()
{
        ios::sync_with_stdio(false);
        string mystring;
        set<string> words;
        string other;
        while (cin >> mystring) {
                string other;
                for (auto it : mystring) {
                        if (in_range_1(it)) {
                                if (it >= 'A' && it <= 'Z')
                                        it += 'a'-'A';
                                other.pb(it);
                        } else  {
                                if (not other.empty())
                                        words.insert(other);
                                other = "";
                        }
                }
                if (not other.empty())
                        words.insert(other);
        }
        for (auto it : words) {
                cout << it;
                cout << "\n";
        }
        return 0;
}
