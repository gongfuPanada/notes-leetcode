"""
	035. Search Insert Position
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/search-insert-position/
	@time: 48 ms
"""

class Solution(object):
    def searchInsert(self, nums, target):
        beg, end = 0, len(nums)-1
        while beg <= end:
            mid = (beg + end) / 2
            if nums[mid] == target: return mid
            elif nums[mid] < target: beg = mid+1
            else: end = mid-1
        return min(len(nums), beg)
