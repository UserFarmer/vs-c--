#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public: void gameOfLife(vector<vector<int>>& board) {
            int neighbors[3] = {0, 1, -1};

            int row = board.size();
            int col = board.size();

            vector<vector<int>> copy(row, vector<int>(col, 0));

            for (int r = 0; r < row; r++){
                for (int c = 0; c < col; c++) {
                    copy[r][c] = board[r][c];
                }
            }

            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col;c++) {
                    int live = 0;

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3;j++) {
                            if(!(neighbors[i] ==0  && neighbors[j] == 0)) {
                                int rr = r + neighbors[i];
                                int cc = c + neighbors[j];

                                if((rr<r && rr>=0) && (cc<c && cc>= 0) && (copy[rr][cc] == 1)) {
                                    live += 1;
                                }
                            }
                        }
                    }
                    if((copy[r][c] == 1) && (live<2||live>3)) {
                        board[r][c] = 0;
                    }
                    if(copy[r][c] == 0 && live == 3) {
                        board[r][c] = 1;
                    }
                }
            }
    }
};

int main() {
    vector<vector<int>> board = {{1,1},{1,0}};
    Solution p;
    p.gameOfLife(board);

    system("pause");
    return 0;
}