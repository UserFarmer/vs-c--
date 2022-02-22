/*
给你一个数组 nums 和一个值 val
你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0;
        int slow = 0;
        for (; fast < nums.size(); fast++) {
            if(nums[fast] != val) {
                swap(nums[fast], nums[slow]);
                slow++;
            }
        }
        return slow;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int ans1;

    int ans = s.removeElement(nums, val);
    cout << ans << endl;
    for(auto it:nums)
        cout << it << ' ';
    return 0;
}