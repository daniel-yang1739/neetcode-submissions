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
     * @return {boolean}
     */
    isBalanced(root) {
        let isBalanced = true;

        function maxDepthDFS(root) {
            if (!root) return 0;
            const left = maxDepthDFS(root.left);
            const right = maxDepthDFS(root.right);
            isBalanced &&= (Math.abs(left - right) <= 1);
            return Math.max(left, right) + 1;
        }

        maxDepthDFS(root);
        return isBalanced;
    }
}
