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
     * @param {ListNode} l1
     * @param {ListNode} l2
     * @return {ListNode}
     */
    addTwoNumbers(l1, l2) {
        const dummy = new ListNode();
        let node = dummy, carry = 0;
        while (l1 || l2 || carry) {
            let l1_val = l1 ? l1.val : 0;
            let l2_val = l2 ? l2.val : 0;
            let summary = l1_val + l2_val + carry;
            node.next = new ListNode(summary % 10);
            node = node.next;
            carry = Math.floor(summary / 10);
            l1 = l1 ? l1.next : l1;
            l2 = l2 ? l2.next : l2;
        }
        return dummy.next;
    }
}
