#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    long long a, b;
    cin >> a >> b;

    long long full_blocks = a / b;
    long long remainder = a % b;

    long long sum = 0;
    sum += full_blocks * (b * (b - 1LL) / 2); // b-1LL ensures 64-bit math
    sum += remainder * (remainder + 1) / 2;

    cout << sum << endl;
  }

  return 0;
}
