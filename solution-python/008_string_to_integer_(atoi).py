"""
	008. String to Integer (atoi)
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/string-to-integer-(atoi)/
	@time: 64 ms
"""

class Solution:
    def myAtoi(self, str):
        str = str.lstrip()
        res, n, tag = 0, len(str), False
        if n:
            tag = str[0] == "-"
            pos = 1 if str[0] == "+" or str[0] == "-" else 0
            while pos < n:
                digit = str[pos]
                pos += 1
                if "0" <= digit <= "9":
                    res = res * 10 + int(digit)
                else:
                    break
        return max(-res, -2147483648) if tag else min(res, 2147483647)
