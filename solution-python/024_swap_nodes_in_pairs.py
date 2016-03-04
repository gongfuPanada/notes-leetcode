"""
	024. Swap Nodes in Pairs
	@name: li jin
	@date: Mar 03, 2016
	@link: https://leetcode.com/problems/swap-nodes-in-pairs/
	@time: 40 ms
"""
class Solution(object):
    def swapPairs(self, head):
        if not head or not head.next:
            return head
        new_head = head.next
        head.next = new_head.next
        new_head.next = head
        head.next = self.swapPairs(head.next)
        return new_head
