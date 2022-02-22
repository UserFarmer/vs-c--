/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

输入：s = "We are happy."
输出："We%20are%20happy."
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(auto it:s) {
            if(it==' ') {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
            else {
                ans.push_back(it);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str = "We are happy";
    string ans = s.replaceSpace(str);


    cout << ans << endl;

    system("pause");
    return 0;
}