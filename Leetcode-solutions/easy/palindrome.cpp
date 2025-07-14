// If neg ret false or last dig is neg ret false else reverse and check if = to x then true
class Solution
{
public:
  bool isPalindrome(int x)
  {
    int n = x;
    int dig1 = n % 10;
    long long rev = 0;
    if (x < 0)
    {
      return false;
    }
    else if (x == 0)
    {
      return true;
    }
    else if (dig1 == 0)
    {
      return false;
    }

    while (n != 0)
    {
      int dig = n % 10;
      rev = rev * 10 + dig;
      n = n / 10;
    }
    if (rev == x)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};