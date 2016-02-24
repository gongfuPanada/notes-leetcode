/*
	006. ZigZag Conversion
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/zigzag-conversion/
	@time: 16 ms
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans = s;
        int p = 0, n = s.length(), delta = 2*numRows - 2;
        for (int i = 0; i < numRows; i++) {
            int j1 = i, j2 = delta - i;
            while (j1 < n) {
                ans[p++] = s[j1];
                j1 += delta;
                if (i == 0 || i == numRows - 1) continue;
                if (j2 < n) ans[p++] = s[j2];
                j2 += delta;
            }
        }
        return ans;
    }
};
