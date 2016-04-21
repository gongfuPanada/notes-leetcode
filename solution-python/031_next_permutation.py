"""
	031. Next Permutation
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/next-permutation/
	@time: 64 ms
"""

class Solution(object):
    def nextPermutation(self, nums):
        for i in range(len(nums) - 1, -1, -1):
            k = len(nums)
            while nums[i] < nums[k-1]:
                k -= 1
            if i < k < len(nums):
                nums[i], nums[k] = nums[k], nums[i]
                break
            else:
                nums[i:] = sorted(nums[i:])
