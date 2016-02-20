/*
	012. Integer to Roman
	@name: li jin
	@date: Feb 21, 2016
	@link: https://leetcode.com/problems/integer-to-roman/
	@time: 8 ms
*/

public class Solution {
    private static final String[][] roman_list = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, {"", "M", "MM", "MMM"}};
    public String intToRoman(int num) {
        String res = "";
        int d = 0;
        while (num > 0) {
            res = roman_list[d++][num % 10] + res;
            num /= 10;
        }
        return res;
    }
}
