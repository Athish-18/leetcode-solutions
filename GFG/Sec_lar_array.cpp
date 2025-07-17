class Solution
{
public:
  int getSecondLargest(vector<int> &arr)
  {
    // code here

    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = n - 2; i >= 0; i--)
    {
      if (arr[i] != arr[n - 1])
      {
        return arr[i];
      }
    }
    return -1;
  }
};

// C++ program to find the second largest element in the array
// using one traversal

#include <iostream>
#include <vector>
using namespace std;

// function to find the second largest element in the array
int getSecondLargest(vector<int> &arr)
{
  int n = arr.size();

  int largest = -1, secondLargest = -1;

  // finding the second largest element
  for (int i = 0; i < n; i++)
  {

    // If arr[i] > largest, update second largest with
    // largest and largest with arr[i]
    if (arr[i] > largest)
    {
      secondLargest = largest;
      largest = arr[i];
    }

    // If arr[i] < largest and arr[i] > second largest,
    // update second largest with arr[i]
    else if (arr[i] < largest && arr[i] > secondLargest)
    {
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

int main()
{
  vector<int> arr = {12, 35, 1, 10, 34, 1};
  cout << getSecondLargest(arr);

  return 0;
}

// C++ program to find the second largest element in the array
// using two traversals

#include <iostream>
#include <vector>
using namespace std;

// function to find the second largest element in the array
int getSecondLargest(vector<int> &arr)
{
  int n = arr.size();

  int largest = -1, secondLargest = -1;

  // finding the largest element
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > largest)
      largest = arr[i];
  }

  // finding the second largest element
  for (int i = 0; i < n; i++)
  {

    // Update second largest if the current element is greater
    // than second largest and not equal to the largest
    if (arr[i] > secondLargest && arr[i] != largest)
    {
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

int main()
{
  vector<int> arr = {12, 35, 1, 10, 34, 1};
  cout << getSecondLargest(arr);

  return 0;
}