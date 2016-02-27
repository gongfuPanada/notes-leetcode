/*
	017. Letter Combinations of a Phone Number
	@name: li jin
	@date: Feb 28, 2016
	@link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
	@time: 0 ms
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string letters[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (auto d : digits) {
            if (ans.size() > 0) {
                vector<string> tmp;
                for (auto c : letters[d - '0']) {
                    for (auto s : ans) {
                        tmp.push_back(s + c);
                    }
                }
                ans = tmp;
            }
            else {
                for (auto c : letters[d - '0']) {
                    stringstream ss;
                    ss << c;
                    ans.push_back(ss.str());
                }
            }
        }
        return ans;
    }
};