/*
	033. Search in Rotated Sorted Array
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/search-in-rotated-sorted-array/
	@time: 4 ms
*/

class Solution {
public:
    int search_helper(vector<int>& nums, int target, int low, int high) {
        if (low > high) return -1;
        if (low == high) return target == nums[low] ? low : -1;
        int mid = (high + low) >> 1;
        if (target == nums[mid]) return mid;
        if (target > nums[mid]) {
            if (nums[high] > target) return search_helper(nums, target, mid+1, high);
            int tmp = search_helper(nums, target, mid+1, high);
            if (tmp == -1) return search_helper(nums, target, low, mid-1);
            else return tmp;
        } else {
            if (nums[low] < target) return search_helper(nums, target, low, mid-1);
            int tmp = search_helper(nums, target, low, mid-1);
            if (tmp == -1) return search_helper(nums, target, mid+1, high);
            else return tmp;
        }
    }

    int search(vector<int>& nums, int target) {
        return search_helper(nums, target, 0, nums.size()-1);
    }
};
