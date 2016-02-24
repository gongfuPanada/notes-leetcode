/*
	013. Roman to Integer
	@name: li jin
	@date: Feb 23, 2016
	@link: https://leetcode.com/problems/roman-to-integer/
	@time: 40 ms
*/

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int roman_map[256];
        roman_map['I'] = 1;
				roman_map['V'] = 5;
				roman_map['X'] = 10;
				roman_map['L'] = 50;
				roman_map['C'] = 100;
				roman_map['D'] = 500;
				roman_map['M'] = 1000;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && roman_map[s[i]] < roman_map[s[i+1]]) result -= roman_map[s[i]];
            else result += roman_map[s[i]];
        }
        return result;
    }
};
