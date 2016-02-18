"""
	003. Longest Substring Without Repeating Characters
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
	@time: 88 ms
"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        idx = {}
        ans = a = b = 0
        for c in s:
            if c in idx and idx[c] >= a:
                ans = max(ans, b - a)
                a = idx[c] + 1
            idx[c] = b
            b += 1
        return max(ans, b - a)
