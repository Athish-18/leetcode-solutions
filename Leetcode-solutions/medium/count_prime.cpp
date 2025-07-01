class Solution
{
public:
  int countPrimes(int n)
  {
    int cnt = 0;
    vector<bool> prime(n, true); // use size n, not n+1 because we want primes < n
    if (n > 0)
      prime[0] = false;
    if (n > 1)
      prime[1] = false;

    for (int i = 2; i < n; i++)
    {
      if (prime[i])
      {
        cnt++;
        for (int j = i * 2; j < n; j += i)
        {
          prime[j] = false;
        }
      }
    }

    return cnt;
  }
};
