"""
	018. 4Sum
	@name: li jin
	@date: Mar 02, 2016
	@link: https://leetcode.com/problems/4sum/
	@time: 120 ms
"""

class Solution(object):
    def fourSum(self, nums, target):
        nums.sort()
        n = len(nums)
        ans = []
        for i in xrange(n-3):
            if i and nums[i] == nums[i-1]: continue
            if nums[i] + sum(nums[-3:]) < target: continue
            if sum(nums[i:i+4]) > target: break
            for j in xrange(i+1, n-2):
                if j > i+1 and nums[j] == nums[j-1]: continue
                if nums[i] + nums[j] + sum(nums[-2:]) < target: continue
                if nums[i] + sum(nums[j:j+3]) > target: break
                k, l = j+1, n-1
                tmp_target = target - nums[i] - nums[j]
                while k < l:
                    if nums[k] + nums[l] == tmp_target:
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        k += 1
                        l -= 1
                        while k < l and nums[k] == nums[k-1]: k += 1
                        while k < l and nums[l] == nums[l+1]: l -= 1
                    elif nums[k] + nums[l] < tmp_target:
                        k += 1
                    else:
                        l -= 1

        return ans
