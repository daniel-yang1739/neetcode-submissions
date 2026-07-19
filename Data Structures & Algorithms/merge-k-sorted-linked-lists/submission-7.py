# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:   
    def conquer(
        self, list1: List[Optional[ListNode]], list2: List[Optional[ListNode]]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        node = dummy
        while list1 and list2:
            if list1.val < list2.val:
                node.next = list1
                list1 = list1.next
            else:
                node.next = list2
                list2 = list2.next
            node = node.next
        if list1:
            node.next = list1
        else:
            node.next = list2
        return dummy.next

    def divide(self, lists, l, r):
        if l > r:
            return None
        if l == r:
            return lists[l]
        mid = (l + r) // 2
        left = self.divide(lists, l, mid)
        right = self.divide(lists, mid + 1, r)
        return self.conquer(left, right)

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        return self.divide(lists, 0, len(lists) - 1)
        