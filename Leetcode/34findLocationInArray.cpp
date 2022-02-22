/*
力扣34
给定一个按照升序排列的整数数组 nums，和一个目标值 target。
找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
*/

/*
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int binarySearch(vector<int> &nums, int target, bool lower) {
    int left = 0, right = (int)nums.size() - 1;
    int ans = (int)nums.size();
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] > target || (lower && nums[mid] >= target)) {
        right = mid - 1;
        ans = mid;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }

  vector<int> serach(vector<int> &num, int target) {
    int leftId = binarySearch(num, target, true);
    int rightId = binarySearch(num, target, false) - 1;
    if (leftId <= rightId && rightId < num.size() && num[leftId] == target &&
        num[rightId] == target) {
      return vector<int>{leftId, rightId};
    }
    return vector<int>{-1, -1};
  }
};

int main() {
  int a = 8;
  Solution s;
  vector<int> nums{5, 7, 7, 8, 8, 10};
  vector<int> ans;
  ans = s.serach(nums, a);

  for (auto i = ans.begin(); i < ans.end(); i++) {
    cout << *i << endl;
  }

  system("pause");

  return 0;
}