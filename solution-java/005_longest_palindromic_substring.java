/*
	005. Longest Palindromic Substring
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/longest-palindromic-substring/
	@time: 12 ms
*/

public class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int beg = 0, len = 1;
        int pos = 0;
        while (pos < n) {
            if (n - pos <= len / 2) break;
            int i = pos, j = pos;
            while (j < n - 1 && s.charAt(j) == s.charAt(j+1)) j++;
            pos = j + 1;
            while (j < n - 1 && i > 0 && s.charAt(i-1) == s.charAt(j+1)) {j++; i--;}
            if (j - i + 1 > len) {
                len = j - i + 1;
                beg = i;
            }
        }
        return s.substring(beg, beg+len);
    }
}
