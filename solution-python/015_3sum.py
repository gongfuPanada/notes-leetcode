"""
	015. 3Sum
	@name: li jin
	@date: Feb 21, 2016
	@link: https://leetcode.com/problems/3sum/
	@time: 192 ms
"""

class Solution(object):
    def threeSum(self, nums):
        nums = sorted(nums)
        cur, n, ans = 0, len(nums), []
        if n and nums[-1] < 0:
            return ans
        while cur < n - 2 and nums[cur] <= 0:
            pivot = - nums[cur]
            beg, end = cur + 1, n - 1
            while beg < end:
                if nums[beg] + nums[end] == pivot:
                    ans.append([nums[cur], nums[beg], nums[end]])
                    beg += 1
                    while beg < end and nums[beg] == nums[beg - 1]:
                        beg += 1
                    end -= 1
                    while beg < end and nums[end] == nums[end + 1]:
                        end -= 1
                elif beg < end and nums[beg] + nums[end] < pivot:
                        beg += 1
                else:
                        end -= 1
            cur += 1
            while cur < n and nums[cur] == nums[cur - 1]:
                cur += 1
        return ans
