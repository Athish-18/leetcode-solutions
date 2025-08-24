class Solution
{
public:
  bool rotateString(string s, string goal)
  {
    int i = 0;
    string temp = s;
    while (i <= s.length())
    {
      temp += temp[0];
      temp.erase(0, 1);
      if (temp == goal)
      {
        return true;
      }
      i++;
    }
    return false;
  }
};