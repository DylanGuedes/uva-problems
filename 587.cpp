#include <iostream>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

using ii = pair<int, int>;
using dd = pair<double, double>;
map<string, dd> mymap;
const double unit = sqrt(2)/2;

#define FOR(i, j, k)for(int i=j;i<k;++i)

int main()
{
    mymap.emplace("N", dd(0,1));
    mymap.emplace("NE", dd(unit,unit));
    mymap.emplace("E", dd(1,0));
    mymap.emplace("SE", dd(unit,-unit));
    mymap.emplace("S", dd(0,-1));
    mymap.emplace("SW", dd(-unit,-unit));
    mymap.emplace("W", dd(-1,0));
    mymap.emplace("NW", dd(-unit,unit));

    string mystring;
    int count=0;
    while (cin >> mystring) {
        if (mystring == "END")
            return 0;
        int n;
        string direction;
        char buffer;
        istringstream iss(mystring);
        dd pos(0,0);
        while (iss >> n) {
            direction = "";

            iss >> buffer;
            if (buffer != ',' && buffer != '.')
                direction.push_back(buffer);

            iss >> buffer;
            if (buffer != ',' && buffer != '.')
                direction.push_back(buffer);

            while (buffer!=',' && buffer!='.')
                iss >> buffer;

            dd that_direction = mymap[direction];
            pos.first += that_direction.first*n;
            pos.second += that_direction.second*n;
        }
        count++;
        printf("Map #%d\n", count);
        printf("The treasure is located at (%.3f,%.3f).\n", pos.first, pos.second);
        printf("The distance to the treasure is %.3f.\n", hypot(pos.first, pos.second));
        printf("\n");
    }
    return 0;
}
