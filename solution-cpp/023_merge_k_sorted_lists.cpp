/*
	023. Merge k Sorted Lists
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/merge-k-sorted-lists/
	@time: 404 ms
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int beg, int end) {
        if (end - beg <= 0) return NULL;
        if (end - beg == 1) return lists[beg];
        if (end - beg == 2) return mergeTwoLists(lists[beg], lists[beg+1]);
        int mid = (end + beg) / 2;
        return mergeTwoLists(mergeKLists(lists, beg, mid), mergeKLists(lists, mid, end));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size());
    }
};
