#include <iostream>
#include <vector>

using namespace std;

int binarySearchFirstMatchGreater(vector<int>& nums, int target)
{
  int lo = 0, hi = nums.size() - 1;

  while (lo < hi)
  {
    int mid = lo + (hi - lo) / 2;

    if (nums[mid] <= target) lo = mid + 1;
    else hi = mid;
  }
  
  if (nums.size() && nums[lo] > target) return lo;
  else return -1;
}

int binarySearchFirstMatchGreaterOrEqual(vector<int>& nums, int target)
{
  int lo = 0, hi = nums.size() - 1;

  while (lo < hi)
  {
    int mid = lo + (hi - lo) / 2; 

    if (nums[mid] < target) lo = mid + 1;  // n --> floor(n / 2)
    else hi = mid; // if n is even, n --> floor(n / 2)
                   // if n is odd, n --> floor(n / 2) + 1
  }

  if (nums.size() && nums[lo] >= target) return lo;
  else return -1;
}

int binarySearchLastMatchLess(vector<int>& nums, int target)
{
  int lo = 0, hi = nums.size() - 1;

  while (lo < hi)
  {
    int mid = lo + (hi - lo) / 2 + 1;

    if (nums[mid] >= target) hi = mid - 1;
    else lo = mid;
  }

  if (nums.size() && nums[lo] < target) return lo;
  else return -1;
}

int binarySearchLastMatchLessOrEqual(vector<int>& nums, int target)
{
  int lo = 0, hi = nums.size() - 1;

  while (lo < hi)
  {
    int mid = lo + (hi - lo) / 2 + 1;

    if (nums[mid] > target) hi = mid - 1; // if n is even, n --> floor(n / 2)
                                          // if n is odd, n --> floor(n / 2) + 1
    else lo = mid; // n --> floor(n / 2)
  }

  if (nums.size() && nums[lo] <= target) return lo;
  else return -1;
}

int main()
{
  while (true)
  {
    int n;
    cin >> n;
    
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int target;
    cin >> target;

    int res1 = binarySearchFirstMatchGreater(nums, target);
    int res2 = binarySearchFirstMatchGreaterOrEqual(nums, target);
    int res3 = binarySearchLastMatchLess(nums, target);
    int res4 = binarySearchLastMatchLessOrEqual(nums, target);

    cout << res1;
    if (res1 >= 0) cout << '\t' << nums[res1];
    cout << endl;

    cout << res2;
    if (res2 >= 0) cout << '\t' << nums[res2];
    cout << endl;

    cout << res3;
    if (res3 >= 0) cout << '\t' << nums[res3];
    cout << endl;

    cout << res4;
    if (res4 >= 0) cout << '\t' << nums[res4];
    cout << endl;
  }
  
  return 0;
}
