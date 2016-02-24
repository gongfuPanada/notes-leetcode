/*
	004. Median of Two Sorted Arrays
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/median-of-two-sorted-arrays/
	@time: 5 ms
*/

public class Solution {
    // find k-th smallest member
    int findKthSmallest(int k, int[] nums1, int s1, int n1, int[] nums2, int s2, int n2) {
        if (n1 == 0) return nums2[s2+k-1];
        if (n2 == 0) return nums1[s1+k-1];
        if (k == 1) return Integer.min(nums1[s1], nums2[s2]);
        if (k == n1 + n2) return Integer.max(nums1[s1+n1-1], nums2[s2+n2-1]);
        int r1 = Integer.max(1, (int) 1.0 * k * n1 / (n1+n2));
        int r2 = k - r1;
        if (nums1[s1+r1-1] == nums2[s2+r2-1])
            return nums1[s1+r1-1];
        if (nums1[s1+r1-1] < nums2[s2+r2-1])
            return findKthSmallest(r2, nums1, s1+r1, n1-r1, nums2, s2, r2);
        else
            return findKthSmallest(r1, nums1, s1, r1, nums2, s2+r2, n2-r2);
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        if ((n1+n2) % 2 == 1) { // odd
            return 1.0 * findKthSmallest((n1+n2+1) / 2, nums1, 0, n1, nums2, 0, n2);
        } else { // even
            return 0.5 * (findKthSmallest((n1+n2) / 2, nums1, 0, n1, nums2, 0, n2) + findKthSmallest((n1+n2) / 2 + 1, nums1, 0, n1, nums2, 0, n2));
        }
    }
}
