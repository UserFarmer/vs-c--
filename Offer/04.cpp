/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。
*/

/*
输入：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
输入5，返回true 输入20，返回false
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;

        int x = 0;
        int y = matrix.size() - 1;

        while(x < matrix[0].size() && y >= 0) {
            if(matrix[y][x] > target) {
                y--;
            }
            else if(matrix[y][x] < target) {
                x++;
            }
            else if(matrix[y][x] == target) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 20;

    bool ans = s.findNumberIn2DArray(matrix, target);
    cout << boolalpha << ans << endl;

    system("pause");
    return 0;
}