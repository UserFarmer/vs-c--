#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
   int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }   
        return majority;
   }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int ans = s.majorityElement(nums);
    cout << ans << endl;
    return 0;
}