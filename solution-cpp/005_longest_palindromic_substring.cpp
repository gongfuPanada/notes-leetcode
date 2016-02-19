/*
	005. Longest Palindromic Substring
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/longest-palindromic-substring/
	@time: 140 ms
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int beg = 0, len = 1;
        bool pali[n][n];
        pali[n - 1][n - 1] = true;
        for (int i = 0; i < n - 1; i++) {
            pali[i][i] = true;
            pali[i + 1][i] = true;
        }
        for (int k = 1; k < n; k++) {
            for (int i = 0; i + k < n; i++) {
                if (pali[i + 1][i + k - 1] && s[i] == s[i + k]) {
                    pali[i][i + k] = true;
                    len = k + 1;
                    beg = i;
                } else {
                    pali[i][i + k] = false;
                }
            }
        }
        return s.substr(beg, len);
    }
};
