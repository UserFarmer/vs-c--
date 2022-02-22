/*
给定一个已按照非递减顺序排列的整数数组 numbers
请你从数组中找出两个数满足相加之和等于目标数 target

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。
numbers 的下标 从 1 开始计数 ，
所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
*/

/*
输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left<right) {
            int sum = numbers[left] + numbers[right];
            if(sum==target)
                return {left + 1, right + 1};
                else if(sum<target)
                    left++;
                    else if(sum>target)
                        right--;
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 6;
    Solution s;
    vector<int> ans;

    ans = s.twoSum(nums, target);
    for(auto it:ans)
        cout << it <<' ';

    return 0;
            
}