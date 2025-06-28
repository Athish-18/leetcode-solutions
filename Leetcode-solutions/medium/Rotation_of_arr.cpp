class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    vector<int> temp(nums.size());
    for (int i = 0; i < temp.size(); i++)
    {
      temp[(k + i) % temp.size()] = nums[i];
    }
    nums = temp;
  }
};