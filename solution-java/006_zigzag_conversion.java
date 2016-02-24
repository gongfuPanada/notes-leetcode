/*
	006. ZigZag Conversion
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/zigzag-conversion/
	@time: 5 ms
*/

public class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        int p = 0, n = s.length(), delta = 2 * numRows - 2;
        char[] ans = new char[n];
        for (int i = 0; i < numRows; i++) {
            int j1 = i, j2 = delta - i;
            while (j1 < n) {
                ans[p++] = s.charAt(j1);
                j1 += delta;
                if (i % (numRows-1) == 0) continue;
                if (j2 < n) ans[p++] = s.charAt(j2);
                j2 += delta;
            }
        }
        return new String(ans);
    }
}
