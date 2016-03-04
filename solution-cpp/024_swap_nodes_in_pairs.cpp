/*
	024. Swap Nodes in Pairs
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* new_head = head->next;
        head->next = new_head->next;
        new_head->next = head;
        head->next = swapPairs(head->next);
        return new_head;
    }
};
