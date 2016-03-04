/*
	018. 4Sum
	@name: li jin
	@date: Mar 02, 2016
	@link: https://leetcode.com/problems/4sum/
	@time: 16 ms
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        int i = 0, j, k, l;
        for (int i = 0; i < n - 3 && nums[i] + nums[i+1] + nums[i+2] + nums[i+3] <= target; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
            for (int j = i + 1; j < n - 2 && nums[i] + nums[j] + nums[j+1] + nums[j+2] <= target; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                int tmp_target = target - nums[i] - nums[j];
                k = j + 1, l = n - 1;
                while (k < l) {
                    if (tmp_target == nums[k] + nums[l]) {
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[l]);
                        res.push_back(tmp);
                        tmp.clear();
                        do {l--;} while (k < l && nums[l] == nums[l+1]);
                        do {k++;} while (k < l && nums[k] == nums[k-1]);
                    }
                    else if (tmp_target > nums[k] + nums[l]) k++;
                    else l--;
                }
            }
        }
        return res;
    }
};
