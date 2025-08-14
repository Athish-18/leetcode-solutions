class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int low = 1;
    int high = nums.size() - 2;
    int mid = low + (high - low) / 2;

    if (nums.size() == 1)
    {
      return nums[0];
    }
    else if (nums[0] != nums[1])
    {
      return nums[0];
    }
    else if (nums[nums.size() - 1] != nums[nums.size() - 2])
    {
      return nums[nums.size() - 1];
    }

    while (low <= high)
    {
      int x = nums[mid];
      if (nums[mid - 1] != x && nums[mid + 1] != x)
      {
        return nums[mid];
      }
      else
      {
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {

          // move right
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
      mid = low + (high - low) / 2;
    }
    return -1;
  }
};