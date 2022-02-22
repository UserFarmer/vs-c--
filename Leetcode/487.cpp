/*
给定一个二进制数组，你可以最多将 1 个 0 翻转为 1，
找出其中最大连续 1 的个数。
*/

/*
输入：[1,0,1,1,0]
输出：4
解释：翻转第一个 0 可以得到最长的连续 1。
     当翻转以后，最大连续 1 的个数为 4。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        int flag = 0;
        int ans = 0;
        int n = 0;
        for (; fast < nums.size(); fast++) {
            if(nums[fast] == 1) {
                n++;
                if(fast == nums.size() - 1)
                    ans = max(ans, n);
            }
            else if(nums[fast] == 0 && flag == 0) {
                slow = fast;
                nums[slow] = 1;
                n++;
                flag = 1;
            }
            else if(nums[fast] == 0 && flag == 1) {
                ans = max(ans, n);
                nums[slow] = 0;
                n = fast - slow;
                slow = fast;
            }
        }
        return max(ans, n);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, 1, 1, 0};

    int ans = s.findMaxConsecutiveOnes(nums);
    cout << ans << endl;

    system("pause");
    return 0;
}