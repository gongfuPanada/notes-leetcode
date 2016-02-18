/*
	003. Longest Substring Without Repeating Characters
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
	@time: 6 ms
*/

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] idx= new int[256];
        for (int i = 0; i < 256; idx[i++] = -1);
        int ans = 0;
        int a, b;
        for (a = b = 0; b < s.length(); b++) {
            ans = Math.max(ans, b - a);
            a = Math.max(a, idx[s.charAt(b)] + 1);
            idx[s.charAt(b)] = b;
        }
        return Math.max(ans, b - a);
    }
}
