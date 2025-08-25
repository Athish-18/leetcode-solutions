class Solution
{
public:
  int maxDepth(string s)
  {
    int max_dep = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '(')
      {
        count++;
        max_dep = max(max_dep, count);
      }
      else if (s[i] == ')')
      {
        count--;
      }
    }
    return max_dep;
  }
};