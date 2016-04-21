/*
	032. Longest Valid Parentheses
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/longest-valid-parentheses/
	@time: 8 ms
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack_paren;
        int longest_valid[s.size()+1] = {0};
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == '(') {
                stack_paren.push(i);
            } else {
                if (stack_paren.empty()) continue;
                int idx = stack_paren.top();
                stack_paren.pop();
                longest_valid[i+1] = longest_valid[idx] + i - idx + 1;
                res = max(res, longest_valid[i+1]);
            }
        }
        return res;
    }
};
