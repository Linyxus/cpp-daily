#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};

struct Area
{
    Point v;
    int w, h;
};

bool in(Point p, Area a)
{
    int dx = p.x - a.v.x;
    int dy = p.y - a.v.y;
    return (dx >= 0 && dx <= a.w) && (dy >= 0 && dy <= a.h);
}

int main()
{
    int n;
    vector<Area> arr;
    Point p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Area a;
        cin >> a.v.x >> a.v.y >> a.w >> a.h;
        arr.push_back(a);
    }
    cin >> p.x >> p.y;
    for (int i = arr.size()-1; i >= 0; i--) {
        if (in(p, arr[i])) {
            cout << i+1;
            return 0;
        }
    }
    cout << -1;

    return 0;
}
