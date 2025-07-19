class Solution
{
public:
  bool isPerfectSquare(int num)
  {
    int sqrt_of_num = sqrt(num); // here if sqrt of num lets say 28 -- is not a int like 5.3214 -- on sqaring type casted to int so wont give 28 ans
    if (sqrt_of_num * sqrt_of_num == num)
    {
      return true;
    }
    return false;
  }
};

// another approach is to find all the factors and then push into an array and if u get on squaring the individual ele == number then yes else no
