/*
	031. Next Permutation
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/next-permutation/
	@time: 10 ms
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            int k = nums.size();
            while (nums[i] < nums[k-1]) k--;
            if (k < nums.size() && k > i) {
                swap(nums[i], nums[k]);
                break;
            }
            else {
                sort(nums.begin()+i, nums.end());
            }
        }
    }
};
