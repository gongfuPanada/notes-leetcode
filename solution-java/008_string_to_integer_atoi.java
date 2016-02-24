/*
	008. String to Integer (atoi)
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/string-to-integer-(atoi)/
	@time: 3 ms
*/

public class Solution {
    public int myAtoi(String str) {
        int n = str.length(), pos = 0;
        boolean tag = false;
        double res = 0.0;
        if (n > 0) {
            while (str.charAt(pos) == ' ') pos++;
            tag = str.charAt(pos) == '-';
            if(tag || str.charAt(pos) == '+') pos++;
            while (pos < str.length()) {
                char digit = str.charAt(pos++);
                if (digit < '0' || digit > '9') break;
                if(res > 2147483647 || res == 2147483647 && digit > '7')
                    return tag ? Integer.MIN_VALUE : Integer.MAX_VALUE;
                res = res*10 + digit - '0';
            }
        }
        return (int) (tag ? -res : res);
    }
}
