# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepthDFS(self, root: Optional[TreeNode], is_balanced: List[bool]) -> int:
        if not root:
            return 0
        left = self.maxDepthDFS(root.left, is_balanced)
        right = self.maxDepthDFS(root.right, is_balanced)
        is_balanced[0] &= (abs(left - right) <= 1)
        return max(left, right) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        is_balanced = [True]
        self.maxDepthDFS(root, is_balanced)
        return is_balanced[0]
        