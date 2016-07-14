#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int x_pos, y_pos;
char ori;
map<char, pair<int, int> > mymap;
bool warning[50][50];

char get_left()
{
    switch (ori) {
        case 'N':
            return 'W';

        case 'S':
            return 'E';

        case 'E':
            return 'N';

        case 'W':
            return 'S';
    }
}

char get_right()
{
    switch (ori) {
        case 'N':
            return 'E';

        case 'S':
            return 'W';

        case 'E':
            return 'S';

        case 'W':
            return 'N';
    }
}

void undo(char instr)
{
    switch (instr) {
        case 'L':
            ori = get_right();
            break;
        case 'R':
            ori = get_left();
            break;

        case 'F':
            x_pos -= mymap[ori].first;
            y_pos -= mymap[ori].second;
            break;
    }
}

void move(char instr)
{
    switch (instr) {
        case 'L':
            ori = get_left();
            break;
        case 'R':
            ori = get_right();
            break;

        case 'F':
            x_pos += mymap[ori].first;
            y_pos += mymap[ori].second;
            break;
    }
}

int main()
{
    int columns, lines;
    string instructions;
    mymap.insert(make_pair('W', make_pair(-1, 0)));
    mymap.insert(make_pair('S', make_pair(0, -1)));
    mymap.insert(make_pair('E', make_pair(1, 0)));
    mymap.insert(make_pair('N', make_pair(0, 1)));

    cin >> columns >> lines;
    memset(warning, false, sizeof warning);
    while (cin >> x_pos >> y_pos >> ori) {
        bool lost = false;
        cin >> instructions;
        string lost_instruction;
        for (auto it : instructions) {
            move(it);
            if (x_pos > columns || y_pos > lines || x_pos < 0 || y_pos < 0) {
                undo(it);
                if (warning[y_pos][x_pos]) {
                    // undo(it);
                } else {
                    lost = true;
                    warning[y_pos][x_pos] = true;
                    break;
                }
            }
        }

        if (lost) {
            printf("%d %d %c LOST\n", x_pos, y_pos, ori);
        } else {
            printf("%d %d %c\n", x_pos, y_pos, ori);
        }
    }
}
