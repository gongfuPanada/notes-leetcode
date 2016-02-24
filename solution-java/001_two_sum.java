/*
	001. Two Sum
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/two-sum/
	@time: 7 ms
*/

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
        int i = 0;
        for (int n : nums) {
            if (hmap.containsKey(n))
                return new int[]{hmap.get(n), i};
            hmap.put(target-n, i++);
        }
        return null;
    }
}
