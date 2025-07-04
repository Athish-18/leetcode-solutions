class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    int i = 0; // points to last unique element

    for (int j = 1; j < nums.size(); j++)
    {
      if (nums[j] != nums[i])
      {
        i++;               // move to next position
        nums[i] = nums[j]; // copy unique element
      }
    }

    return i + 1; // new length
  }
};
