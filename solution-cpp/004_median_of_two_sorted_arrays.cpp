/*
	004. Median of Two Sorted Arrays
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/median-of-two-sorted-arrays/
	@time: 40 ms
*/

class Solution {
public:
    // find k-th smallest member
    int findKthSmallest(int k, vector<int>& nums1, int s1, int n1, vector<int>& nums2, int s2, int n2) {
        if (n1 == 0) return nums2[s2+k-1];
        if (n2 == 0) return nums1[s1+k-1];
        if (k == 1) return min(nums1[s1], nums2[s2]);
        if (k == n1 + n2) return max(nums1[s1+n1-1], nums2[s2+n2-1]);
        int r1 = max(1, int(1.0 * k * n1 / (n1+n2)));
        int r2 = k - r1;
        if (nums1[s1+r1-1] == nums2[s2+r2-1])
            return nums1[s1+r1-1];
        if (nums1[s1+r1-1] < nums2[s2+r2-1])
            return findKthSmallest(r2, nums1, s1+r1, n1-r1, nums2, s2, r2);
        else
            return findKthSmallest(r1, nums1, s1, r1, nums2, s2 + r2, n2-r2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if ((n1+n2) % 2) { // odd
            return 1.0 * findKthSmallest((n1+n2+1) / 2, nums1, 0, n1, nums2, 0, n2);
        } else { // even
            return 0.5 * (findKthSmallest((n1+n2) / 2, nums1, 0, n1, nums2, 0, n2) + findKthSmallest((n1+n2) / 2 + 1, nums1, 0, n1, nums2, 0, n2));
        }
    }
};
