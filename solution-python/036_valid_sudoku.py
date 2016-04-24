"""
	036. Valid Sudoku
	@name: li jin
	@date: Apr 24, 2016
	@link: https://leetcode.com/problems/valid-sudoku/
	@time: 88 ms
"""

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        tt = [[[False for i in range(9)] for j in range(9)] for k in range(3)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    idx = ord(board[i][j]) - ord('1')
                    k = i / 3 * 3 + j / 3
                    if tt[0][i][idx] or tt[1][j][idx] or tt[2][k][idx]:
                        return False
                    tt[0][i][idx] = True
                    tt[1][j][idx] = True
                    tt[2][k][idx] = True
        return True
