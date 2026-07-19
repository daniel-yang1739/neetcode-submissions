# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # Get center node
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # Reverse right-half list
        node = slow.next
        prev = slow.next = None
        while node:
            node_next = node.next
            node.next = prev
            prev = node
            node = node_next
        # Cross linked for reordering list
        first = head
        second = prev
        while second:
            node = second.next
            second.next = first.next
            first.next = second
            first = second.next
            second = node