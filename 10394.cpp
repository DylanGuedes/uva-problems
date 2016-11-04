#include <bits/stdc++.h>

using namespace std;

bool is_prime[400000];
#define repi(i, j, k)for(int i=j;i<k;++i)
using ll = long long;
vector<ll> primes;
#define pb push_back
using ii = pair<ll, ll>;
#define eb emplace_back

int main()
{
        memset(is_prime, true, sizeof is_prime);

        const ll highest = 10000000000;
        vector<ii> resp;
        is_prime[1] = false;
        is_prime[0] = false;

        primes.pb(2);
        int check = sqrt(highest);
        for (unsigned long long int i=3; i<check; i+=2) {
                if (!is_prime[i])
                        continue;
                if (is_prime[i-2])
                        resp.eb(i, i-2);
                int that = check/i;
                for (unsigned long long int j=2; j<=that; j++) {
                        is_prime[i*j] = false;
                }
                primes.pb(i);
        }

        int n;
        while (cin >> n) {
                cout << "(" << resp[n-1].second << ", " << resp[n-1].first << ")\n";
        }
        return 0;
}
