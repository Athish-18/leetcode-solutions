class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    string word = "";
    sort(strs.begin(), strs.end());

    for (int j = 0; j < strs[0].size(); j++)
    {
      if (strs[0][j] == strs[strs.size() - 1][j])
      {
        word += strs[0][j];
      }
      else
      {
        break;
      }
    }

    return word;
  }
};