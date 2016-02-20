/*
	012. Integer to Roman
	@name: li jin
	@date: Feb 21, 2016
	@link: https://leetcode.com/problems/integer-to-roman/
	@time: 44 ms
*/

class Solution {
private:
    string roman_list[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, {"", "M", "MM", "MMM"}};
public:
    string intToRoman(int num) {
        string res = "";
        int d = 0;
        while (num) {
            res = roman_list[d++][num % 10] + res;
            num /= 10;
        }
        return res;
    }
};
