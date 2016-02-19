"""
	007. Reverse Integer
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/reverse-integer/
	@time: 56 ms
"""

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            return -self.reverse(-x)
        res = 0.0
        while x:
            res = res * 10 + x % 10
            x /= 10
        return int(res) if -2147483648 <= res <= 2147483647 else 0
