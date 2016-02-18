/*
	003. Longest Substring Without Repeating Characters
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
	@time: 16 ms
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx[256];
        for (int i = 0; i < 256; idx[i++] = -1);
        int ans = 0;
        int a, b;
        for (a = b = 0; b < s.length(); b++) {
            ans = max(ans, b - a);
            a = max(a, idx[s[b]] + 1);
            idx[s[b]] = b;
        }
        return max(ans, b - a);
    }
};
