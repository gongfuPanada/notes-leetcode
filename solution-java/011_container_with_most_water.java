/*
	011. Container With Most Water
	@name: li jin
	@date: Feb 21, 2016
	@link: https://leetcode.com/problems/container-with-most-water/
	@time: 3 ms
*/

public class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int area = 0;
        while (i < j) {
            int lo = height[i];
            int hi = height[j];
            if (lo < hi) {
                area = Integer.max(area, (j - i) * height[i]);
                while (i < j && height[i] <= lo) i++;
            }
            else {
                area = Integer.max(area, (j - i) * height[j]);
                while (i < j && height[j] <= hi) j--;
            }
        }
        return area;
    }
}
