/*
	028. Implement strStr
	@name: li jin
	@date: Mar 17, 2016
	@link: https://leetcode.com/problems/implement-strstr/
	@time: 4 ms
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle) return i;
        }
        return n ? -1 : 0;
    }
};
