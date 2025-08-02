#include <algorithm>
using namespace std;

class Solution
{
public:
  void nextPermutation(vector<int> &A)
  {
    int n = A.size();
    int ind = -1;

    // Step 1: Find the first decreasing element from the right
    for (int i = n - 2; i >= 0; i--)
    {
      if (A[i] < A[i + 1])
      {
        ind = i;
        break;
      }
    }

    // Step 2: If no such element, reverse entire array and return
    if (ind == -1)
    {
      reverse(A.begin(), A.end());
      return; // ✅ return early!
    }

    // Step 3: Find the next greater element to the right of ind
    for (int i = n - 1; i > ind; i--)
    {
      if (A[i] > A[ind])
      {
        swap(A[i], A[ind]);
        break;
      }
    }

    // Step 4: Reverse the suffix after ind
    reverse(A.begin() + ind + 1, A.end());
  }
};
