"""
	025. Reverse Nodes in k-Group
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/reverse-nodes-in-k-group/
	@time: 68 ms
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        pre, pre.next = self, head
        while self.needReverse(head, k):
            tail = head  # 1st one in cur KGroup
            for _ in xrange(k):
                pre.next, head.next, head = head, pre.next, head.next
            pre = tail  # now, it become the last one in previous KGroup
        pre.next = head  #maybe there are some rest node.
        return self.next

    def needReverse(self, head, k):
        while head and k:
            k -= 1
            head = head.next
        return k == 0
