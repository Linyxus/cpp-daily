#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5000 + 5;
int x[maxn];

void qread(int &d)
{
    char ch = getchar();
    d = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        d = d * 10 + ch - '0';
        ch = getchar();
    }
}

int main()
{
    int L, N;
    qread(L);
    qread(N);
    int min_t = 0;
    for (int i = 0; i < N; i++) {
        qread(x[i]);
        int l = x[i];
        int r = L+1 - x[i];
        int t = r < l ? r : l;
        min_t = min_t > t ? min_t : t;
    }
    printf("%d ", min_t);
    sort(x, x + N);

    return 0;
}
