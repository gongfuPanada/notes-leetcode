/*
	014. Longest Common Prefix
	@name: li jin
	@date: Feb 23, 2016
	@link: https://leetcode.com/problems/longest-common-prefix/
	@time: 4 ms
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ans = strs[0];
        int n = ans.size();
        for (auto s : strs) {
            while (n && s.substr(0, n) != ans) {
                n--;
                ans = ans.substr(0, n);
            }
            if (n == 0) return "";
        }
        return ans;
    }
};
