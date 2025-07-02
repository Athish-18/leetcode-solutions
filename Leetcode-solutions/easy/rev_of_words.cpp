class Solution
{
public:
  string reverseWords(string s)
  {
    int end = s.length() - 1;
    string result = "";

    while (end >= 0)
    {
      // Skip trailing spaces
      while (end >= 0 && s[end] == ' ')
        end--;

      // Mark word end
      int wordEnd = end;

      // Move to start of word
      while (end >= 0 && s[end] != ' ')
        end--;

      // Extract the word
      if (wordEnd >= 0)
      {
        if (!result.empty())
          result += ' '; // Add space before appending next word
        result += s.substr(end + 1, wordEnd - end);
      }
    }

    return result;
  }
};
