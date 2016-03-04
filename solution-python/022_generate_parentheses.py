"""
	022. Generate Parentheses
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/generate-parentheses/
	@time: 48 ms
"""

class Solution(object):
    def generateParenthesis(self, n):
        ans = []
        def generate(s, ln, rn):
            if ln == 0 and rn == 0:
                ans.append(s)
            else:
                if ln:
                    generate(s + '(', ln-1, rn+1)
                if rn:
                    generate(s + ')', ln, rn-1)
        generate("", n, 0)
        return ans;
