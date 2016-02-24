/*
	010. Regular Expression Matching
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/regular-expression-matching/
	@time: 8 ms
*/

class Solution {
public:
    bool helper(vector<vector<int>> &f, string &s, int i, string &p, int j) {
        if (f[i][j] != -1)
            return f[i][j];

        if (j == p.length())
            f[i][j] = i == s.length();
        else if (j + 1 < p.length() && p[j+1] == '*')
            f[i][j] = helper(f, s, i, p, j+2) || i < s.length() && (s[i] == p[j] || p[j] == '.') && helper(f, s, i+1, p, j);
        else
            f[i][j] = i < s.length() && (s[i] == p[j] || p[j] == '.') && helper(f, s, i+1, p, j+1);

        return f[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> f(s.length()+1, vector<int>(p.length()+1, -1));
        return helper(f, s, 0, p, 0);
    }
};
