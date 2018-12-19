# #2 下一个完全平方数 解答

### 代码

```c++
#include <iostream>
using namespace std;

int find_next_square(int N)
{
  for (int i = 0; true; i++) {
    int t = i * i;
    if (t == N) return (i+1) * (i+1);
    if (t > N) return -1;
  }
}

int main()
{
  int N;
  cin >> N;
  cout << find_next_square(N) << endl;

  return 0;
}
```

### 解析

啦啦啦啦啦

讲一个小技巧吧！

也许你注意到了，这个循环：

```c++
for (int i = 0; true; i++) {
    int t = i * i;
    if (t == N) return (i+1) * (i+1);
    if (t > N) return -1;
}
```

看起来不同寻常。它的判断条件直接写成了`true`。

等价的写法还有：

```c++
int i = 0;
while (true) {
    // ...
    i++;
}
```

```c++
for (int i = 0; ; i++) {
    // ...
}
```

当然也有皮一点的

```c++
while (0 == 0) {
    //...
    i++;
}
```

```c++
for (int i = 0; 3.141592653 > 2.718281828; i++) {
    //...
}
```

这种循环的作用就是创建一个**死循环**。所以，循环里一定要用`return`或者`break`跳出去才行啊。