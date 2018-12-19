# #6 3D模型 解答

### 代码

```c++
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
```

### 解析

解决该问题的思路很简单。

方便起见，将模型的周围一圈都设置为高度为0的空地。

上方面积和底部面积都很好求，即为高度大于0的格子数量。

侧面积的求法也很容易，检查所有相邻的格子，他们之间暴露出的面积即为他们高度之差的绝对值。