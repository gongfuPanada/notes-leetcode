"""
	004. Median of Two Sorted Arrays
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/median-of-two-sorted-arrays/
	@time: 124 ms
"""

class Solution(object):
    def kth(self, k, nums1, nums2):
        n1, n2 = len(nums1), len(nums2)
        if n1 == 0:
            return nums2[k - 1]
        if n2 == 0:
            return nums1[k - 1]
        if k == 1:
            return min(nums1[0], nums2[0])
        if k == n1 + n2:
            return max(nums1[-1], nums2[-1])
        r1 = max(1, int(1.0 * k * n1 / (n2 + n1)))
        r2 = k - r1
        if nums1[r1 - 1] == nums2[r2 - 1]:
            return nums1[r1 - 1]
        if nums1[r1 - 1] < nums2[r2 - 1]:
            return self.kth(r2, nums1[r1:], nums2[:r2])
        else:
            return self.kth(r1, nums1[:r1], nums2[r2:])

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n1, n2 = len(nums1), len(nums2)
        if (n1 + n2) % 2:
            return 1.0 * self.kth((n1 + n2 + 1) / 2, nums1, nums2)
        else:
            return 0.5 * (self.kth((n1 + n2) / 2, nums1, nums2) + self.kth((n1 + n2) / 2 + 1, nums1, nums2))
