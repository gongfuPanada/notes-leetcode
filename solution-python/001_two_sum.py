"""
	001. Two Sum
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/two-sum/
	@time: 56 ms
"""

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i, n in enumerate(nums):
            if n in d:
                return [d[n], i]
            d[target - n] = i
