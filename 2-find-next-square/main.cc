#include <iostream>
using namespace std;

int find_next_square(int N)
{
  for (int i = 0; ; i++) {
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
