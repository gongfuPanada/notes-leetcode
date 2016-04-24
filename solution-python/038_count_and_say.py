"""
	038. Count and Say
	@name: li jin
	@date: Apr 24, 2016
	@link: https://leetcode.com/problems/count-and-say/
	@time: 52 ms
"""

class Solution:
    def countAndSay(self, n):
        if n == 1:
            return "1"
        else:
            s = self.countAndSay(n-1)
            res = ""
            p = s[0]
            n = 0
            for c in s:
                if c == p:
                    n += 1
                else:
                    res += "{}{}".format(n, p)
                    p = c
                    n = 1
            res += "{}{}".format(n, p)
            return res
