/*
	016. 3Sum Closest
	@name: li jin
	@date: Feb 28, 2016
	@link: https://leetcode.com/problems/3sum-closest/
	@time: 8 ms
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[len-1] + nums[len-2] + nums[len-3] <= target) 
            return nums[len-1] + nums[len-2] + nums[len-3];
        if (nums[0] + nums[1] + nums[2] >= target) 
            return nums[0] + nums[1] + nums[2];
        int candidate;
        int diff = 2147483647;
        for (int pos = 0; pos < len - 2; pos++) {
            if (pos > 0 && nums[pos] == nums[pos-1]) continue;
            if (nums[pos] + nums[len-2] + nums[len-1] <= target) {
                candidate = nums[pos] + nums[len-1] + nums[len-2];
                diff = candidate - target;
                continue;
            }
            int target_tmp = target - nums[pos];
            int beg = pos + 1, end = len - 1;
            while (beg < end) {
                int sum_tmp = nums[beg] + nums[end];
                if (abs(sum_tmp - target_tmp) < abs(diff)) {
                    diff = sum_tmp - target_tmp;
                }
                if (sum_tmp > target_tmp) {
                    do {
                        end--;
                    } while (nums[end] == nums[end+1]);
                }
                else if(sum_tmp < target_tmp) {
                    do {
                        beg++;
                    } while (nums[beg] == nums[beg-1]);
                }
                else return target;
            }
        }
        return target + diff;
    }
};