"""
	016. 3Sum Closest
	@name: li jin
	@date: Feb 28, 2016
	@link: https://leetcode.com/problems/3sum-closest/
	@time: 68 ms
"""

class Solution(object):
    def threeSumClosest(self, nums, target):
        nums.sort()
        n = len(nums)
        if sum(nums[:3]) >= target:
            return sum(nums[:3])
        if sum(nums[-3:]) <= target:
            return sum(nums[-3:])
        diff = sum(nums[:3]) - target;
        for pos in xrange(n - 2):
            if pos > 0 and nums[pos] == nums[pos-1]:
                continue
            if nums[pos] + nums[n-2] + nums[n-1] <= target:
                candidate = nums[pos] + nums[n-1] + nums[n-2]
                diff = candidate - target
                continue
            target_tmp = target - nums[pos]
            beg, end = pos + 1, n - 1
            while beg < end:
                sum_tmp = nums[beg] + nums[end]
                if abs(sum_tmp - target_tmp) < abs(diff):
                    diff = sum_tmp - target_tmp
                if sum_tmp > target_tmp: 
                    end -= 1
                    while nums[end] == nums[end + 1]:
                        end -= 1
                elif sum_tmp < target_tmp:
                    beg += 1
                    while nums[beg] == nums[beg - 1]:
                        beg += 1
                else:
                    return target
        return target + diff
        