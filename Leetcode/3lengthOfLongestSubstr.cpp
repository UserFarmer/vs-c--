/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    //滑动窗口
    unordered_set<char> hash;
    int left = 0;
    int right = 0;
    int ans = 0;

    for (; right < s.size(); right++) {
      while (hash.find(s[right]) != hash.end()) {
        hash.erase(s[left]);
        left++;
      }
      ans = max(ans, right - left + 1);
      hash.insert(s[right]);
    }
    return ans;
  }
};

int main() {
  Solution s;
  string str = "abcabc";
  int ans = s.lengthOfLongestSubstring(str);

  cout << ans << endl;
}