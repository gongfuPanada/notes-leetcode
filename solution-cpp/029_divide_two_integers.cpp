/*
	029. Divide Two Integers
	@name: li jin
	@date: Mar 17, 2016
	@link: https://leetcode.com/problems/divide-two-integers/
	@time: 4 ms
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)  return 0;
        if(divisor==0)  return INT_MAX;

        double t1=log(fabs(dividend));
        double t2=log(fabs(divisor));
        long long result = double(exp(t1 - t2));
        if((dividend < 0) ^ (divisor < 0))  result = -result;
        if(result > INT_MAX)  result = INT_MAX;
        if(result < INT_MIN)  result = INT_MAX;
        return result;
    }
};
