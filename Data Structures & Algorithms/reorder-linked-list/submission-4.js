/**
 * Definition for singly-linked list.
 * class ListNode {
 *     constructor(val = 0, next = null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

class Solution {
    /**
     * @param {ListNode} head
     * @return {void}
     */
    reorderList(head) {
        // Get center node
        let slow = head, fast = head.next;
        while (fast && fast.next) {
            slow = slow.next;
            fast = fast.next.next;
        }
        // Reverse list
        let node = slow.next;
        let prev = slow.next = null;
        while (node) {
            const node_next = node.next;
            node.next = prev;
            prev = node;
            node = node_next;
        }
        // Cross linked for reordering list
        let first = head, second = prev;
        while (second) {
            const node = second.next;
            second.next = first.next;
            first.next = second;
            first = second.next;
            second = node;
        }
    }
}
