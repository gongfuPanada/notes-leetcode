/*
	027. Remove Element
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/remove-element/
	@time: 4 ms
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx, cur;
        int n = nums.size();
        for (idx = cur = 0; idx < n - cur; idx++) {
            if (nums[idx] == val) {
                do {
                    cur++;
                } while (idx < n - cur && nums[n - cur] == val);
                if (idx < n - cur) nums[idx] = nums[n - cur];
            }
        }
        return n - cur;
    }
};
