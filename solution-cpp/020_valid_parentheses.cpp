/*
	020. Valid Parentheses
	@name: li jin
	@date: Mar 02, 2016
	@link: https://leetcode.com/problems/valid-parentheses/
	@time: 0 ms
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> match;
        match['}'] = '{'; match[']'] = '['; match[')'] = '(';
        for (auto c : s) {
            if (match.find(c) != match.end()) {
                if (st.empty() || st.top() != match[c]) return false;
                else st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
