/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (right - left) / 2 + left;

      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else if (nums[mid] > target)
        right = mid - 1;
    }
    return left;
  }
};

int main() {
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  Solution s;
  int ans = s.searchInsert(nums, target);

  cout << ans << endl;

  system("pause");
  return 0;
}