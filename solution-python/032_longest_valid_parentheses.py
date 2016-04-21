"""
	032. Longest Valid Parentheses
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/longest-valid-parentheses/
	@time: 92 ms
"""

class Solution(object):
    def longestValidParentheses(self, s):
        st = []
        pl = [0 for c in s] + [0]
        for i, c in enumerate(s):
            if c == '(':
                st.append(i)
            else:
                if not st:
                    continue
                ix = st.pop()
                pl[i+1] = pl[ix]+i-ix+1
        return max(pl)
