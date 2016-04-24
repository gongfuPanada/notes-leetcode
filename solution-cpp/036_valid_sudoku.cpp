/*
	036. Valid Sudoku
	@name: li jin
	@date: Apr 24, 2016
	@link: https://leetcode.com/problems/valid-sudoku/
	@time: 12 ms
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool nine[3][9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '1';
                    int k = (i/3) * 3 + j / 3;
                    if (nine[0][i][n] || nine[1][j][n] || nine[2][k][n])
                        return false;
                    nine[0][i][n] = true;
                    nine[1][j][n] = true;
                    nine[2][k][n] = true;
                }
            }
        }
        return true;
    }
};
