"""
	014. Longest Common Prefix
	@name: li jin
	@date: Feb 23, 2016
	@link: https://leetcode.com/problems/longest-common-prefix/
	@time: 44 ms
"""

class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ""
        res = strs[0]
        for s in strs:
            while not s.startswith(res):
                if res:
                    res = res[:-1]
                else:
                    return ""
        return res
