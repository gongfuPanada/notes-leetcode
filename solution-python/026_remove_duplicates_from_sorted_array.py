"""
	026. Remove Duplicates from Sorted Array
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	@time: 92 ms
"""

class Solution(object):
    def removeDuplicates(self, nums):
        if len(nums) < 2: return len(nums)
        pos = 1
        for i in xrange(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[pos] = nums[i]
                pos += 1
        del nums[pos:]
        return pos
