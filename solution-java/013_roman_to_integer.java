/*
	013. Roman to Integer
	@name: li jin
	@date: Feb 23, 2016
	@link: https://leetcode.com/problems/roman-to-integer/
	@time: 8 ms
*/

public class Solution {

    public int romanToInt(String s) {
        int result = 0;
        int [] roman_map = new int[256];
        roman_map['I'] = 1;
				roman_map['V'] = 5;
				roman_map['X'] = 10;
				roman_map['L'] = 50;
				roman_map['C'] = 100;
				roman_map['D'] = 500;
				roman_map['M'] = 1000;
        for (int i = 0; i < s.length() - 1; i++) {
            if (roman_map[s.charAt(i)] < roman_map[s.charAt(i + 1)]) result -= roman_map[s.charAt(i)];
            else result += roman_map[s.charAt(i)];
        }
        if (s.length() > 0)
            result += roman_map[s.charAt(s.length() - 1)];
        return result;
    }

}
