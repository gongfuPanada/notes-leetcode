/*
	026. Remove Duplicates from Sorted Array
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	@time: 32 ms
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) nums[res++] = nums[i];
        }
        nums.erase(nums.begin() + res, nums.end());
        return res;
    }
};
