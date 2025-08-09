class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int left = 0;
    int right = 0;
    vector<int> hash(256, -1);
    int maxlen = 0;
    int len = 0;

    while (right < s.length())
    {
      if (hash[s[right]] != -1)
      {
        if (left <= hash[s[right]])
        {
          left = hash[s[right]] + 1;
        }
      }
      hash[s[right]] = right;
      len = right - left + 1;
      maxlen = max(maxlen, len);

      right++;
    }

    return maxlen;
  }
};