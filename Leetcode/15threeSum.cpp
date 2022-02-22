// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
// 使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 输入：nums = []
// 输出：[]
// 输入：nums = [0]
// 输出：[]

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3) //当数组元素不足时
      return ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) //当排序后的最小元素也大于0时
        return ans;

      if (i > 0 && nums[i] == nums[i - 1]) //去重：重复的数字，跳过
        continue;

      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        if (nums[left] + nums[right] + nums[i] > 0)
          right--;
        else if (nums[left] + nums[right] + nums[i] < 0)
          left++;
        else {
          ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
          left++;
          right--;
          while (left < right && nums[left] == nums[left - 1])
            left++;
          while (left < right && nums[right] == nums[right + 1])
            right--;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> ans = s.threeSum(nums);
  for (vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); ++it) {
    for (int i = 0; i < (*it).size(); i++)
      cout << (*it)[i] << ' ';
  }
  return 0;
}