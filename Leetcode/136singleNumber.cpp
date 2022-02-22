// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
// 找出那个只出现了一次的元素。
// 输入: [2,2,1]
// 输出: 1
// 输入: [4,1,2,1,2]
// 输出: 4

//不使用额外空间：位运算
//根据异或的性质：(a1⊕a1)⊕(a2⊕a2)⊕...⊕(am⊕am)⊕an=an
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int singleNumber(vector<int> & nums) {
        int tmp = 0;
        for(auto it:nums)
            tmp ^= it;
        return tmp;
    }
};

int main() {
    vector<int> num = {4, 1, 2, 1, 2};
    Solution s;
    int ans = s.singleNumber(num);

    cout << ans << endl;
    system("pause");
    return 0;
}