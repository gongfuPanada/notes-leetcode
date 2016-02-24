/*
	008. String to Integer (atoi)
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/string-to-integer-(atoi)/
	@time: 8 ms
*/

class Solution {
public:
    int myAtoi(string str) {
        int n = str.length(), pos = 0;
        bool tag = false;
        double res = 0.0;
        if (n) {
            while (str[pos] == ' ') pos++;
            tag = str[pos] == '-';
            if(tag || str[pos] == '+') pos++;
            while (pos < str.length()) {
                char digit = str[pos++];
                if (digit < '0' || digit > '9') break;
                res = res*10 + digit - '0';
                if (res >= 2147483648)
                    return tag ? -2147483648 : 2147483647;
            }
        }
        return int(tag ? -res : res);
    }
};
