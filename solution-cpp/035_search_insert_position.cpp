/*
	035. Search Insert Position
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/search-insert-position/
	@time: 8 ms
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = nums.size();
        while (beg <= end) {
            int mid = (beg + end) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) beg = mid+1;
            else end = mid-1;
        }
        return min(beg, int(nums.size()));
    }
};
