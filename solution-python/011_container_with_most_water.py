"""
	011. Container With Most Water
	@name: li jin
	@date: Feb 21, 2016
	@link: https://leetcode.com/problems/container-with-most-water/
	@time: 68 ms
"""

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i, j = 0, len(height) - 1
        area = 0
        while i < j:
            lo, hi = height[i], height[j]
            if lo < hi:
                area = max(area, (j - i) * lo)
                while i < j and height[i] <= lo:
                    i += 1
            else:
                area = max(area, (j - i) * hi)
                while i < j and height[j] <= hi:
                    j -= 1
        return area
