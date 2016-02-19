"""
	005. Longest Palindromic Substring
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/longest-palindromic-substring/
	@time: 128 ms
"""

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n, beg, size, pos = len(s), 0, 1, 0
        while pos < n:
            if n - pos <= size / 2: break
            i, j = pos, pos
            while j < n - 1 and s[j] == s[j + 1]:
                j += 1
            pos = j + 1
            while j < n - 1 and i > 0 and s[i - 1] == s[j + 1]:
                i, j = i - 1, j + 1
            if j - i + 1 > size:
                beg, size = i, j - i + 1
        return s[beg : beg + size]
