/*
	025. Reverse Nodes in k-Group
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/reverse-nodes-in-k-group/
	@time: 25 ms
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
private:
    bool hasK(ListNode* head, int k) {
        ListNode* cur = head;
        while (cur && k) {
            cur = cur->next;
            k--;
        }
        return k == 0;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *root = new ListNode(-1);
        ListNode *pre = root;
        pre->next = head;
        while (hasK(head, k)) {
            ListNode* tail = head;
            for (int i = 0; i < k; i++) {
                ListNode *tmp = head->next;
                head->next = pre->next;
                pre->next = head;
                head = tmp;
            }
            pre = tail;
        }
        pre->next = head;
        return root->next;
    }
};
