"""
	034. Search for a Range
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/search-for-a-range/
	@time: 48 ms
"""

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        beg, end = 0, len(nums) - 1
        while beg <= end:
            mid = (beg + end) / 2
            if nums[mid] == target:
                b, e = mid+1, mid-1
                while b > 0 and nums[b-1] == target:
                    b -= 1
                while e < len(nums)-1 and nums[e+1] == target:
                    e += 1
                return [b, e]
            elif nums[mid] > target:
                end = mid-1
            else:
                beg = mid+1

        return [-1, -1]
