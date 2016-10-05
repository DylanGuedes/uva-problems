#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

class card {
public:
        int position;
        string abbr, comp;
        card() { }
};

vector<card> cards;

bool myfunc(card c1, card c2)
{
        return c1.position < c2.position;
}

int main()
{
        ios::sync_with_stdio(false);
        int n;
        while (cin >> n) {
                if(!n)
                        return 0;

                cards.clear();
                card c;
                FOR(i, 0, n) {
                        cin >> c.abbr >> c.comp;
                        cards.push_back(c);
                }

                bool used[55];
                memset(used, false, sizeof used);

                int ptr = 1;
                FOR(i, 0, n) {
                        int len = cards[i].comp.size();
                        int yes = 0;
                        while (yes != len) {
                                if (used[ptr]) {
                                } else {
                                        yes++;
                                        if (yes == len)
                                                break;
                                }
                                ptr=(ptr+1)%n;
                        }
                        if (ptr == 0) {
                                used[n] = 1;
                                used[0] = 1;
                                cards[i].position = n;
                        } else {
                                used[ptr] = 1;
                                cards[i].position = ptr;
                        }
                }

                sort(cards.begin(), cards.end(), myfunc);
                int cards_size = cards.size();
                FOR(i, 0, cards_size) {
                        if (i)
                                cout << " ";
                        cout << cards[i].abbr;
                }
                cout << "\n";
        }
        return 0;
}
