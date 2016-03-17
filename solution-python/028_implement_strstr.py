"""
	028. Implement strStr
	@name: li jin
	@date: Mar 17, 2016
	@link: https://leetcode.com/problems/implement-strstr/
	@time: 44 ms
"""

class Solution:
    # @param {string} haystack
    # @param {string} needle
    # @return {integer}
    def strStr(self, haystack, needle):
        return haystack.find(needle)
