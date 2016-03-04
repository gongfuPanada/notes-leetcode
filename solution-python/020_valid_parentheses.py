"""
	020. Valid Parentheses
	@name: li jin
	@date: Mar 02, 2016
	@link: https://leetcode.com/problems/valid-parentheses/
	@time: 40 ms
"""

class Solution(object):
    def isValid(self, s):
        lp = {'(', '{', '['}
        rp = {')' : '(', '}' : '{', ']' : '['}
        stack = []
        for c in s:
            if c in lp:
                stack.append(c)
            elif not stack or stack[-1] != rp[c]:
                return False
            else:
                stack.pop(-1)
        return len(stack) == 0
