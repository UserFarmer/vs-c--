/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = 1;
        for (int i = 0; i < n; i++)
            max *= 10;
        vector<int> ans;
        for (int i = 1; i < max; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<int> ans = s.printNumbers(n);

    for(auto it:ans) {
        cout << it << endl;
    }

    system("pause");
    return 0;
}