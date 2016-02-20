"""
	010. Regular Expression Matching
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/regular-expression-matching/
	@time: 72 ms
"""

class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m, n = len(s), len(p)
        f = [[None for j in xrange(n + 1)] for i in xrange(m + 1)]
        def helper(i, j):
            if f[i][j] is not None:
                return f[i][j]
            if j == n:
                f[i][j] = i == m
            elif j + 1 < n and p[j + 1] == '*':
                f[i][j] = helper(i, j + 2) or (i < m and (s[i] == p[j] or p[j] == '.') and helper(i + 1, j))
            else:
                f[i][j] = i < m and (s[i] == p[j] or p[j] == '.') and helper(i + 1, j + 1)
            return f[i][j]

        return helper(0, 0)
