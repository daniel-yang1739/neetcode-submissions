# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        prev_group = dummy
        while True:
            k_node = prev_group
            for _ in range(k):
                k_node = k_node.next
                if k_node is None:
                    return dummy.next
            next_group = k_node.next
            prev = k_node.next
            curr = prev_group.next
            while curr != next_group:
                curr_next = curr.next
                curr.next = prev
                prev = curr
                curr = curr_next
            tmp = prev_group.next
            prev_group.next = prev
            prev_group = tmp
        return dummy.next