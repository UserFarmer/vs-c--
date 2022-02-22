// 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，
// 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色
// 输入：nums = [2,0,2,1,1,0]
// 输出：[0,0,1,1,2,2]
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    for (int i = 0; i <= right; i++) {
      while (i <= right && nums[i] == 2) {
        swap(nums[i], nums[right]);
        right--;
      }
      if (nums[i] == 0) {
        swap(nums[i], nums[left]);
        left++;
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  s.sortColors(nums);
  for (auto it : nums) {
    cout << it << endl;
  }
  return 0;
}