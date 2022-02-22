//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
/*
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        int n = nums.size();
        int i = 0;
        for (; i < n; i++) {
            ans[(i + k) % n] = nums[i];
        }
        nums.assign(ans.begin(), ans.end());
    }

    void reverseRotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        left = 0;
        right = k - 1;
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        left = k;
        right = nums.size() - 1;
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution s;

    s.reverseRotate(nums, k);
    for(auto iter:nums) {
        cout << iter;
    }

    system("pause");
    return 0;
}