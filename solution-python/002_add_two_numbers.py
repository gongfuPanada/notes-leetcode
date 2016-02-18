"""
	002. Add Two Numbers
	@name: li jin
	@date: Feb 19, 2016
	@link: https://leetcode.com/problems/add-two-numbers/
	@time: 136 ms
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        ans = ListNode(0)
        cur = ans
        while l1 or l2 or carry:
            n = carry
            if l1:
                n += l1.val
                l1 = l1.next
            if l2:
                n += l2.val
                l2 = l2.next
            if n > 9:
                carry = 1
                n -= 10
            else:
                carry = 0
            cur.next = ListNode(n)
            cur = cur.next
        return ans.next
