/*
	011. Container With Most Water
	@name: li jin
	@date: Feb 21, 2016
	@link: https://leetcode.com/problems/container-with-most-water/
	@time: 24 ms
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int area = 0;
        while (i < j) {
            int lo = height[i];
            int hi = height[j];
            if (lo < hi) {
                area = max(area, (j - i) * height[i]);
                while (i < j && height[i] <= lo) i++;
            }
            else {
                area = max(area, (j - i) * height[j]);
                while (i < j && height[j] <= hi) j--;
            }
        }
        return area;
    }
};
