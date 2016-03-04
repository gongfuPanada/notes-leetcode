/*
	019. Remove Nth Node From End of List
	@name: li jin
	@date: Mar 02, 2016
	@link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
	@time: 4 ms
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head;
        ListNode *target = head;
        while (n--) {
            tmp = tmp->next;
        }
        if (tmp == NULL) {
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        while (tmp->next) {
            tmp = tmp->next;
            target = target->next;
        }
        tmp = target->next;
        target->next = tmp->next;
        delete tmp;
        return head;
    }
};
