#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(nums[mid] == target)
                return mid;
                else if(nums[mid] <= target)
                    left = mid + 1;
                    else if(nums[mid] >= target)
                        right = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 2;

    int ans = s.search(nums, target);
    cout << ans << endl;

    system("pause");
    return 0;
}