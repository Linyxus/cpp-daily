# #3 人口增长 解答

```c++
#include <iostream>
using namespace std;

int main()
{
  int p0, aug, p;
  double per;
  cin >> p0 >> per >> aug >> p;

  int n = 0;
  int cur = p0;
  while (++n) {
    cur += cur * (per / 100.0) + aug;
    if (cur >= p0) break;
  }

  cout << n << endl;

  return 0;
}
```

本题比较简单。

有一个地方值得一提：

```c++
while (++n) {
    //...
}
```

其实等价于

```c++
while (true) {
    n++;
    //...
}
```

也许之前提及过，`n++`与`++n`的区别在于`n++`返回`n`原来的值，而`++n`返回`n`改变后的值，也就是加上`1`之后的值。

所以这里的`++n`总是一个大于零的值，总是被判定为真值。