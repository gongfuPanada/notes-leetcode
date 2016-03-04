"""
	019. Remove Nth Node From End of List
	@name: li jin
	@date: Mar 02, 2016
	@link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
	@time: 60 ms
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        tmp, cur = head, head
        while n:
            tmp = tmp.next
            n -= 1
        if not tmp:
            return head.next
        while tmp.next:
            tmp = tmp.next
            cur = cur.next

        cur.next = cur.next.next
        return head
