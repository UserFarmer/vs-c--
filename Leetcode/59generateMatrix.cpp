#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int num = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int maxNum = n * n;
    vector<vector<int>> ans(n, vector<int>(n));

    while (num <= maxNum) {
      for (int i = left; i <= right; i++)
        ans[top][i] = num++;
      top++;
      for (int i = top; i <= bottom; i++)
        ans[i][right] = num++;
      right--;
      for (int i = right; i >= left; i--)
        ans[bottom][i] = num++;
      bottom--;
      for (int i = bottom; i >= top; i--)
        ans[i][left] = num++;
      left++;
    }
    return ans;
  }
};

int main() {
  int n;
  Solution s;
  vector<vector<int>> ans;
  cin >> n;

  ans = s.generateMatrix(n);
  for (auto i = ans.begin(); i != ans.end(); i++) {
    for (int j = 0; j < (*i).size(); j++) {
      cout << (*i)[j] << ' ';
    }
    cout << endl;
  }

  system("pause");
  return 0;
}