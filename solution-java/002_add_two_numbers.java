/*
	002. Add Two Numbers
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/add-two-numbers/
	@time: 4 ms
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        int carry = 0, n;
        ListNode cur = ans;
        while (l1 != null || l2 != null || carry != 0) {
            n = carry;
            if (l1 != null) {
                n += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                n += l2.val;
                l2 = l2.next;
            }
            carry = n / 10;
            n %= 10;
            cur.next = new ListNode(n);
            cur = cur.next;
        }
        return ans.next;
    }
}
