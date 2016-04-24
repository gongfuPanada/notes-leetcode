"""
	037. Sudoku Solver
	@name: li jin
	@date: Apr 24, 2016
	@link: https://leetcode.com/problems/sudoku-solver/
	@time: 484 ms
"""

class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def vaild(n):
            r, c = n / 9, n % 9
            t = set("123456789")
            for i in range(9):
                t.discard(board[i][c])
                t.discard(board[r][i])
            for i in range(r/3*3, r/3*3+3):
                for j in range(c/3*3, c/3*3+3):
                    t.discard(board[i][j])
            return t
        def dfs(n):
            if n == 81:
                return True
            r, c = n / 9, n % 9
            if board[r][c] != '.':
                return dfs(n+1)
            else:
                for i in vaild(n):
                    board[r][c] = i
                    if dfs(n+1):
                        return True
                    board[r][c] = '.'
                return False
        dfs(0)
