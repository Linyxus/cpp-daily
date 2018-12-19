#include <iostream>
using namespace std;

const int LIMIT = 1000 + 5;

char h[LIMIT][LIMIT];

int abs(int x)
{
    return x > 0 ? x : -x;
}

int main()
{
    int n, m;
    int bs = 0;
    int s = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
            h[i][j] -= '0';
            if (h[i][j] > 0) bs++;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            s += abs(h[i][j]-h[i+1][j]) + abs(h[i][j]-h[i][j+1]);
        }
    }

    s += 2 * bs;

    cout << s;

    return 0;
}
