class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int low = 0;
    int high = nums.size() - 1;
    int mid = low + (high - low) / 2;
    int ans = INT_MAX;

    while (low <= high)
    {
      if (nums[low] <= nums[mid])
      {
        if (ans > nums[low])
        {
          ans = nums[low];
        }
        low = mid + 1;
      }
      else
      {
        if (ans > nums[mid])
        {
          ans = nums[mid];
        }
        high = mid - 1;
      }
      mid = low + (high - low) / 2;
    }
    return ans;
  }
};