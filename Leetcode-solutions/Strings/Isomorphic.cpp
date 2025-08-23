class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    if (s.size() != t.size())
      return false;

    // arrays to track last seen position of mapping
    int posS[256] = {0};
    int posT[256] = {0};

    for (int i = 0; i < s.size(); i++)
    {
      char c1 = s[i];
      char c2 = t[i];

      // If mismatch in previous mapping → not isomorphic
      if (posS[c1] != posT[c2])
        return false;

      // Mark the position (use i+1 to avoid default 0 conflict)
      posS[c1] = i + 1;
      posT[c2] = i + 1;
    }

    return true;
  }
};