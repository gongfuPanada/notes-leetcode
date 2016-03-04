"""
	023. Merge k Sorted Lists
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/merge-k-sorted-lists/
	@time: 140 ms
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        heap = []
        heapq.heapify(heap)
        for l in lists:
            if l:
                heapq.heappush(heap, (l.val, l))
        head = None
        while heap:
            top = heapq.heappop(heap)
            if not head:
                head, cur = top[1], top[1]
            else:
                cur.next = top[1]
                cur = cur.next
            if top[1].next:
                heapq.heappush(heap, (top[1].next.val, top[1].next))
        return head
