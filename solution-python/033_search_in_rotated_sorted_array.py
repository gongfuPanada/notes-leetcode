"""
	033. Search in Rotated Sorted Array
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/search-in-rotated-sorted-array/
	@time: 44 ms
"""

class Solution(object):
    def search(self, nums, target):
        if not nums:
            return -1
        start = 0; end = len(nums)-1
        while start + 1 < end:
            mid = (start+end)/2
            if nums[mid] == target:
                return mid
            if nums[start] <= target < nums[mid]:
                end = mid
            elif nums[mid] < target <= nums[end]:
                start = mid
            elif nums[mid] > nums[end]: # right side is pivoted
                start = mid
            else:
                end = mid
        if nums[start] == target:return start
        elif nums[end] == target:return end
        return -1
