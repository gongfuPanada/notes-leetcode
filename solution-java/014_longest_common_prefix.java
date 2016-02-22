/*
	014. Longest Common Prefix
	@name: li jin
	@date: Feb 23, 2016
	@link: https://leetcode.com/problems/longest-common-prefix/
	@time: 1 ms
*/

public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String ans = strs[0];
        int n = ans.length();
        for (String s : strs) {
            while (n > 0 && !s.startsWith(ans)) {
                n--;
                ans = ans.substring(0, n);
            }
            if (n == 0) return "";
        }
        return ans;
    }
}
