class Solution
{
public:
  int sumOfTheDigitsOfHarshadNumber(int x)
  {
    int dig;
    int sum = 0;
    int ori = x;
    while (x != 0)
    {
      dig = x % 10;
      sum = sum + dig;
      x = x / 10;
    }

    if (ori % sum == 0)
    {
      return sum;
    }
    else
    {
      return -1;
    }
  }
};