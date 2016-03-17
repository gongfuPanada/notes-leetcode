"""
	027. Remove Element
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/remove-element/
	@time: 46 ms
"""

class Solution(object):
    def removeElement(self, nums, val):
        n, p = len(nums), 0
        i = 0
        while i < n - p:
            if nums[i] == val:
                p += 1
                while p < n - i and nums[-p] == val:
                    p += 1
                if p < n - i:
                    nums[i] = nums[-p]
            i += 1
        return n - p
