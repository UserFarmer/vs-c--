/*
给定一个二进制数组， 计算其中最大连续 1 的个数。
输入：[1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        int ans = 0;
        int n = 0; //中间过渡变量
        for (; fast < nums.size(); fast++) {
            if(nums[fast] == 1) {
                slow = fast;
                n++;
            }
            else if(nums[fast] == 0) {
                n = 0;
            }
            if(ans < n) {
                ans = n;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int ans = s.findMaxConsecutiveOnes(nums);

    cout << ans << endl;

    system("pause");
    return 0;
}