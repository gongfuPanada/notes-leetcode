"""
	013. Roman to Integer
	@name: li jin
	@date: Feb 23, 2016
	@link: https://leetcode.com/problems/roman-to-integer/
	@time: 168 ms
"""

class Solution(object):
    def romanToInt(self, s):
        roman = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        ans, n = 0, len(s)
        for i in xrange(n - 1):
            if roman[s[i + 1]] > roman[s[i]]:
                ans -= roman[s[i]]
            else:
                ans += roman[s[i]]
        if n:
            ans += roman[s[-1]]
        return ans
