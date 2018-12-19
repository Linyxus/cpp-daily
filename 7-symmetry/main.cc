#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 20000+5;

struct Point
{
    int x, y;
};

Point points[maxn];

struct Less
{
    bool operator()(const Point &l, const Point &r) const
    {
        return l.x < r.x;
    }
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }


    Less less;
    sort(points, points+n, less);
}
