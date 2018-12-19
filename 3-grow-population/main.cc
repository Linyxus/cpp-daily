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
