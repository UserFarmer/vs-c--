/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        //双指针
        int left = 0;
        int right = nums.size() - 1;
        while (left<right)
        {
            
            if((nums[left]) % 2 == 0 && (nums[right] % 2) != 0)
                swap(nums[left], nums[right]);
            if((nums[left] % 2) != 0)
                left++;
                else if((nums[right] % 2) == 0)
                    right--;
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = s.exchange(nums);

    for(auto it:ans) {
        cout << it << ' ';
    }

    system("pause");
    return 0;
}