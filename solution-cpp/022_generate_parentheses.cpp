/*
	022. Generate Parentheses
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/generate-parentheses/
	@time: 0 ms
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> strs;
        genParis(strs, "", n, 0);
        return strs;
    }

    void genParis(vector<string> &strs, string str, int left, int right) {
        if (left == 0 && right == 0) {
            strs.push_back(str);
            return;
        }
        if (left > 0) { genParis(strs, str + '(', left - 1, right + 1); }
        if (right > 0) { genParis(strs, str + ')', left, right - 1); }
    }
};
