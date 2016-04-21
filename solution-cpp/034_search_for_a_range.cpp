/*
	034. Search for a Range
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/search-for-a-range/
	@time: 12 ms
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (nums[mid] == target) {
                int b = mid+1, e = mid-1;
                while (b > beg && nums[b-1] == target) b--;
                while (e < end && nums[e+1] == target) e++;
                return vector<int>({b, e});
            } else if (nums[mid] < target) {
                beg = mid+1;
            } else {
                end = mid-1;
            }
        }
        return vector<int>({-1, -1});
    }
};
