"""
	009. Palindrome Number
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/palindrome-number/
	@time: 262 ms
"""

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        t = str(x)
        return t == t[::-1]