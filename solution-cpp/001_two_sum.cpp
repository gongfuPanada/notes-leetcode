/*
	001. Two Sum
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/two-sum/
	@time: 16 ms
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmap;
        int i = 0;
        for (int n:nums) {
            auto t = hmap.find(n);
            if (t != hmap.end())
                return vector<int>{t -> second, i};
            hmap[target-n] = i++;
        }
    }
};
