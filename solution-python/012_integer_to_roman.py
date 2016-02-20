"""
	012. Integer to Roman
	@name: li jin
	@date: Feb 21, 2016
	@link: https://leetcode.com/problems/integer-to-roman/
	@time: 108 ms
"""

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        roman_list = [["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
                      ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
                      ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
                      ["", "M", "MM", "MMM"]]
        res, d = "", 0
        while num:
            res = roman_list[d][num % 10] + res
            d += 1
            num /= 10
        return res
