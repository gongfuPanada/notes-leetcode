/*
	038. Count and Say
	@name: li jin
	@date: Apr 24, 2016
	@link: https://leetcode.com/problems/count-and-say/
	@time: 4 ms
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string ans = "";
        char p = s[0];
        int c = 0;
        for (auto t:s) {
            if (t == p) c++;
            else {
                ans += to_string(c) + p;
                p = t; c = 1;
            }
        }
        ans += to_string(c) + p;
        return ans;
    }
};
