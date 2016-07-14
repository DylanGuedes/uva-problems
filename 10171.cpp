#include <iostream>
#include<map>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

map<char, int> mymap;
map<int, char> reversemap;

int distY[30][30];
int distM[30][30];

int main()
{
    int weight;
    char age, w_type, origin, destination;
    int count = 0;
    int n;

    while (cin >> n) {
        if (not n) return 0;

        mymap.clear();
        reversemap.clear();

        count = 0;
        FOR(i, 0, 30) {
            FOR(j, 0, 30) {
                if (i != j) {
                    distY[i][j] = 0xffffff;
                    distM[i][j] = 0xffffff;
                } else {
                    distY[i][j] = 0;
                    distM[i][j] = 0;
                }
            }
        }

        FOR(i, 0, n) {
            cin >> age >> w_type >> origin >> destination >> weight;

            if (age == 'Y') {
                distY[origin-65][destination-65] = min(distY[origin-65][destination-65], weight);
                if (w_type == 'B') {
                    distY[destination-65][origin-65] = min(distY[destination-65][origin-65], weight);
                }
            } else if (age == 'M') {
                distM[origin-65][destination-65] = min(distM[origin-65][destination-65], weight);
                if (w_type == 'B') {
                    distM[destination-65][origin-65] = min(distM[destination-65][origin-65], weight);
                }
            }
        }
        cin >> origin >> destination;
        int young_node = origin-65;
        int mature_node = destination-65;

        // printf("DISTS BEGIN:\n");
        // FOR(i, 0, mymap.size()) {
        //     FOR(j, 0, mymap.size()) {
        //         printf("distY %d %d = %d\n", i, j, distY[i][j]);
        //         printf("distM %d %d = %d\n", i, j, distM[i][j]);
        //     }
        // }

        FOR(k, 0, 27) {
            FOR(i, 0, 27) {
                FOR(j, 0, 27) {
                    distY[i][j] = min(distY[i][j], distY[i][k] + distY[k][j]);
                    distM[i][j] = min(distM[i][j], distM[i][k] + distM[k][j]);
                }
            }
        }

        // printf("DISTS:\n");
        // FOR(i, 0, 27) {
        //     FOR(j, 0, 27) {
        //         printf("distY %d %d = %d\n", i, j, distY[i][j]);
        //         printf("distM %d %d = %d\n", i, j, distM[i][j]);
        //     }
        // }
        std::map< int, int > myv;

        int mymin = 0xffffff;
        FOR(i, 0, 27) {
            if (distY[young_node][i] != 0xffffff && distM[mature_node][i] != 0xffffff) {
                mymin = min(mymin, distY[young_node][i] + distM[mature_node][i]);
            }
        }

        int mycount = 0;
        if (mymin != 0xffffff) {
            printf("%d ", mymin);
            FOR(i, 0, 26) {
                if (distY[young_node][i]+distM[mature_node][i] == mymin) {
                    if (mycount) {
                        printf(" ");
                    }
                    printf("%c", i+65);
                    mycount++;
                }
            }
            printf("\n");
        } else {
            printf("You will never meet.\n");
        }

    }
    return 0;
}
