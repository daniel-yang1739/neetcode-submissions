# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        node = dummy
        carry = 0
        while l1 or l2 or carry:
            l1_val = l1.val if l1 else 0
            l2_val = l2.val if l2 else 0
            summary = l1_val + l2_val + carry
            node.next = ListNode(summary % 10)
            node = node.next
            carry = summary // 10
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
        return dummy.next
