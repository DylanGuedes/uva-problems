#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, j, k)for(int i=j;i<k;++i)

using ii = pair<int, int>;

struct line {
        int xmin;
        int xmax;
        int ymin;
        int ymax;
};

// l1.x dentro de l2.x
bool cond_i(vector<ii> l1, line l2)
{
        return l1[0].first >= l2.xmin && l1[1].first <= l2.xmax;
}

// l2.x dentro de l1.x
bool cond_ii(vector<ii> l1, line l2)
{
        return l1[0].first <= l2.xmin && l1[1].first >= l2.xmax;
}

// l1.y dentro de l2.y
bool cond_iii(vector<ii> y1, line y2)
{
        return y1[0].second >= y2.ymin && y1[1].second <= y2.ymax;
}

// l2.y dentro de l1.y
bool cond_iv(vector<ii> y1, line y2)
{
        return y1[0].second <= y2.ymin && y1[1].second >= y2.ymax;
}

// x1 totalmente a esquerda
bool cond_v(vector<ii> x1, line x2)
{
        return not (x1[0].first < x2.xmax && x1[1].first < x2.xmin);
}

// x1 totalmente a direita
bool cond_vi(vector<ii> x1, line x2)
{
        return not (x1[1].first < x2.xmin && x1[0].first > x2.xmax);
}

// y1 totalmente a esquerda
bool cond_vii(vector<ii> y1, line y2)
{
        return not (y1[0].second < y2.ymax && y1[1].second < y2.ymin);
}

// y1 totalmente a direita
bool cond_viii(vector<ii> y1, line y2)
{
        return not( y1[1].second < y2.xmin && y1[0].second > y2.xmax);
}

int main()
{
        int n;
        int min_x_square, max_x_square, min_x_line, max_x_line;
        int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
        scanf("%d", &n);
        FOR(z, 0, n) {
                scanf("%d%d%d%d%d%d%d%d", &xstart, &ystart, &xend, &yend, &xleft, &ytop, &xright, &ybottom);
                vector<ii> lines[4];
                lines[0].push_back(ii(min(xleft, xright), min(ytop, ybottom)));
                lines[0].push_back(ii(max(xright, xleft), max(ytop, ybottom)));

                lines[1].push_back(ii(min(xleft, xright), ybottom));
                lines[1].push_back(ii(max(xright, xleft), ybottom));

                lines[2].push_back(ii(xleft, min(ytop, ybottom)));
                lines[2].push_back(ii(xleft, max(ybottom, ytop)));

                lines[3].push_back(ii(xright, min(ytop, ybottom)));
                lines[3].push_back(ii(xright, max(ybottom, ytop)));

                line myline;
                myline.xmin = min(xstart, xend);
                myline.xmax = max(xstart, xend);
                myline.ymin = min(ystart, yend);
                myline.ymax = max(ystart, yend);

                bool flag = false;
                FOR(i, 0, 4) {
                        bool r_i = cond_i(lines[i], myline);
                        bool r_ii = cond_ii(lines[i], myline);
                        bool r_iii = cond_iii(lines[i], myline);
                        bool r_iv = cond_iv(lines[i], myline);
                        bool res_1 = r_i || r_ii;
                        bool res_2 = r_iii || r_iv;
                        if (res_1 && res_2) {
                                flag = true;
                                break;
                        } else {
                                if (res_1) {
                                        int xmin = lines[i][0].first;
                                        int xmax = lines[i][1].first;
                                        int ymin = lines[i][0].second;
                                        int ymax = lines[i][1].second;
                                        printf("ximn: %d, xmax: %d, ymin: %d, ymax: %d\n", xmin, xmax, ymin, ymax);

                                        if (ymin > myline.ymax)
                                                continue;
                                        if (myline.ymin > ymax)
                                                continue;
                                        if (ymax < myline.ymin)
                                                continue;
                                        if (myline.ymax < ymin)
                                                continue;

                                        printf("res1..\n");
                                        flag = true;
                                        break;
                                } else if (res_2) {
                                        int xmin = lines[i][0].first;
                                        int xmax = lines[i][1].first;
                                        int ymin = lines[i][0].second;
                                        int ymax = lines[i][1].second;

                                        if (xmin > myline.xmax)
                                                continue;
                                        if (myline.xmin > xmax)
                                                continue;
                                        if (xmax < myline.xmin)
                                                continue;
                                        if (myline.xmax < xmin)
                                                continue;

                                        printf("res2..\n");
                                        flag = true;
                                        break;
                                }

                        }

                }
                if (flag)
                        printf("T\n");
                else
                        printf("F\n");
        }
        return 0;
}
