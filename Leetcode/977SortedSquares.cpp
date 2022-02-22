#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int flag = nums.size() - 1;
        vector<int> ans(nums.size());

        while(left<=right) {
            if(nums[left]*nums[left]<=nums[right]*nums[right]) {
                ans[flag] = nums[right] * nums[right];
                right--;
                flag--;
            }
            else if(nums[left]*nums[left]>nums[right]*nums[right]) {
                ans[flag] = nums[left] * nums[left];
                left++;
                flag--;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-7,-3,2,3,11};
    Solution s;

    vector<int> ans = s.sortedSquares(nums);
    for(auto i:ans)
        cout << i << ' ';

    system("pause");
    return 0;
}