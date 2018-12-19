#include <iostream>
using namespace std;

int digit_sum(int n, int s = 0)
{
  if (n < 10)
    return s + n;

  return digit_sum(n / 10, s + n % 10);
}

int digital_root(int n)
{
  if (n < 10) return n;

  return digital_root(digit_sum(n));
}

int main()
{
  int n;
  cin >> n;
  cout << digital_root(n);

  return 0;
}
