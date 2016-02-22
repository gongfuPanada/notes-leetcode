/*
	015. 3Sum
	@name: li jin
	@date: Feb 21, 2016
	@link: https://leetcode.com/problems/3sum/
	@time: 9 ms
*/

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length, cur = 0;
        if (n < 3 || nums[n - 1] < 0) return ans;
        while (cur < n - 2 && nums[cur] <= 0) {
            int beg = cur + 1, end = n - 1;
            int pivot = - nums[cur];
            while (beg < end) {
                if (pivot == nums[beg] + nums[end]) {
                    ans.add(Arrays.asList(nums[cur], nums[beg], nums[end]));
                    do { beg++; } while (beg < end && nums[beg] == nums[beg - 1]);
                    do { end--; } while (beg < end && nums[end] == nums[end + 1]);
                } else if (pivot > nums[beg] + nums[end]) {
                    beg++;
                } else {
                    end--;
                }
            }
            do { cur++; } while (cur < n && nums[cur] == nums[cur - 1]);
        }
        return ans;
    }
}
