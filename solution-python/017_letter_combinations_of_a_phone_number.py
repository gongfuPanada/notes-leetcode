"""
	017. Letter Combinations of a Phone Number
	@name: li jin
	@date: Feb 28, 2016
	@link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
	@time: 44 ms
"""

class Solution(object):
    def letterCombinations(self, digits):
        letters = [" ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ans = []
        for d in digits:
            d = int(d)
            if ans:
                tmp = []
                for t in letters[d]:
                    tmp += [a + t for a in ans]
                ans = tmp
            else:
                ans = [t for t in letters[d]]
        return ans