# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        is_balanced = True

        def maxDepthDFS(root: Optional[TreeNode]) -> int:
            nonlocal is_balanced;
            if not root:
                return 0
            left = maxDepthDFS(root.left)
            right = maxDepthDFS(root.right)
            is_balanced &= (abs(left - right) <= 1)
            return max(left, right) + 1

        maxDepthDFS(root)
        return is_balanced
        