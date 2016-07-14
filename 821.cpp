#include <iostream>
#include <map>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int dist[110][110];
map<int, int> mymap;

int main()
{
    int origin, destination;
    int caso = 0;

    while (1) {
        bool flag = false;
        mymap.clear();
        int counter = 0;

        FOR(i,0,101) {
            FOR(j,0,101) {
                dist[i][j] = 0xffffff;
            }
        }

        while (cin >> origin >> destination) {
            if (not (origin | destination)) {
                break;
            } else {
                flag = true;
                if (mymap.find(origin) == mymap.end()) {
                    mymap.insert(make_pair(origin, counter));
                    counter++;
                }

                if (mymap.find(destination) == mymap.end()) {
                    mymap.insert(make_pair(destination, counter));
                    counter++;
                }

                dist[mymap[origin]][mymap[destination]] = 1;
            }

        }

        if (flag == false) {
            break;
        } else {
            int n = mymap.size();
            FOR(k, 0, n) {
                FOR(i, 0, n) {
                   FOR(j, 0, n) {
                       dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                   }
                }
            }

            int total = 0;
            FOR(i, 0, n) {
                FOR(j, 0, n) {
                    if (i != j) {
                        total += dist[i][j];
                    }
                }
            }

            printf("Case %d: average length between pages = %.3f clicks\n", caso+1, (double)total/(mymap.size()*(mymap.size()-1)));

            caso++;
        }
    }
    return 0;
}
