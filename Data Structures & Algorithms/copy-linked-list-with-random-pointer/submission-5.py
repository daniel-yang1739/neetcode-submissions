"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        ori_to_new = {}
        node = head
        while node:
            ori_to_new[node] = Node(node.val)
            node = node.next
        node = head
        while node:
            ori_to_new[node].next = ori_to_new.get(node.next)
            ori_to_new[node].random = ori_to_new.get(node.random)
            node = node.next
        return ori_to_new.get(head)
        