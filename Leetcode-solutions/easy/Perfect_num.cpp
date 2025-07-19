class Solution
{
public:
  bool get_factors(int num)
  {
    vector<int> factors;
    for (int i = 1; i <= sqrt(num); i++)
    {
      if (num % i == 0)
      {
        factors.push_back(i);
        factors.push_back(num / i);

        if (num % i == i)
        {
          factors.push_back(i);
          break;
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < factors.size(); i++)
    {
      if (factors[i] == num)
      {
        continue;
      }
      sum += factors[i];
    }
    if (sum == num)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  bool checkPerfectNumber(int num)
  {

    return get_factors(num);
  }
};