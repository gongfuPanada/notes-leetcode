/*
	009. Palindrome Number
	@name: li jin
	@date: Feb 20, 2016
	@link: https://leetcode.com/problems/palindrome-number/
	@time: 68 ms
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int r = 0, y = x;
        while (y) {
            r *= 10;
            r += y % 10;
            y /= 10;
        }
        return x == r;
    }
};
