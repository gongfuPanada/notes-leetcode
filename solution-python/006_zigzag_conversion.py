"""
	006. ZigZag Conversion
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/zigzag-conversion/
	@time: 116 ms
"""

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1: return s
        ans, n, delta = [], len(s), 2 * numRows - 2
        for i in xrange(numRows):
            j1, j2 = i, delta - i
            while j1 < n:
                ans.append(s[j1])
                j1 += delta
                if i % (numRows - 1) == 0:
                    continue
                if j2 < n:
                    ans.append(s[j2])
                    j2 += delta
        return "".join(ans)
