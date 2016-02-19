/*
	007. Reverse Integer
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/reverse-integer/
	@time: 8 ms
*/

class Solution {
public:
    int reverse(int x) {
        double res = 0.0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res < -2147483648 || res > 2147483647) res = 0;
        return (int) res;
    }
};
