/*
	037. Sudoku Solver
	@name: li jin
	@date: Apr 24, 2016
	@link: https://leetcode.com/problems/sudoku-solver/
	@time: 24 ms
*/

class Solution {
private:
    void check(vector<vector<char>>& board, int n, bool t[]) {
        int r = n / 9, c = n % 9;
        for (int i = 0; i < 9; i++) {
            if (board[i][c] != '.') t[board[i][c] - '1'] = true;
            if (board[r][i] != '.') t[board[r][i] - '1'] = true;
        }
        for (int i = r/3*3; i < (r/3+1) * 3; i++) {
            for (int j = c/3*3; j < (c/3+1) * 3; j++) {
                if (board[i][j] != '.') t[board[i][j] - '1'] = true;
            }
        }
    }
    bool dfs(vector<vector<char>>& board, int n) {
        if (n == 81) {
            return true;
        }
        int r = n / 9, c = n % 9;
        if (board[r][c] != '.') {
            return dfs(board, n+1);
        } else {
            bool t[9] = {false};
            check(board, n, t);
            for (int i = 0; i < 9; i++) if (!t[i]) {
                board[r][c] = i + '1';
                if (dfs(board, n+1)) return true;
                board[r][c] = '.';
            }
            return false;
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }
};
