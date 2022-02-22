/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

给你一个可能存在 重复 元素值的数组 numbers ，
它原来是一个升序排列的数组，并按上述情形进行了一次旋转。
请返回旋转数组的最小元素。
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，
该数组的最小值为1。  
*/

/*
输入：[3,4,5,1,2]
输出：1

输入：[2,2,2,0,1]
输出：0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        //二分查找
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if(numbers[mid] > numbers[right]) {
                left = mid + 1;
            }
            else if(numbers[mid] < numbers[right]) {
                right = mid;
            }
            else if(numbers[mid] == numbers[right]) {
                right--;
            }
        }
        return numbers[left];
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 4, 5, 1, 2, 2};
    int ans = s.minArray(nums);

    cout << ans << endl;

    system("pause");
    return 0;
}