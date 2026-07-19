/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     constructor(val = 0, left = null, right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    /**
     * @param {TreeNode} root
     * @return {number}
     */
    diameterOfBinaryTree(root) {
        let diameter = 0;
        function maxDepthDFS(root) {
            if (!root) return 0;
            let left = maxDepthDFS(root.left);
            let right = maxDepthDFS(root.right);
            diameter = Math.max(diameter, left + right);
            return Math.max(left, right) + 1;
        }
        maxDepthDFS(root);
        return diameter;
    }
}
