/*
	002. Add Two Numbers
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/add-two-numbers/
	@time: 40 ms
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        int carry = 0, n;
        ListNode *cur = ans;
        while (l1 || l2 || carry) {
            n = carry;
            if (l1) {
                n += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                n += l2 -> val;
                l2 = l2 -> next;
            }
            carry = n / 10;
            n %= 10;
            cur -> next = new ListNode(n);
            cur = cur -> next;
        }
        return ans -> next;
    }
};
