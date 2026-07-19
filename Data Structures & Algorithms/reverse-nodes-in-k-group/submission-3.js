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
     * @param {number} k
     * @return {ListNode}
     */
    reverseKGroup(head, k) {
        const dummy = new ListNode(0, head);
        let prevGroup = dummy;
        while (true) {
            let kNode = prevGroup;
            for (let i = 0; i < k; ++i) {
                kNode = kNode.next;
                if (!kNode) return dummy.next;
            }
            let nextGroup = kNode.next;
            let prev = kNode.next;
            let curr = prevGroup.next;
            while (curr != nextGroup) {
                let next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }
            let tmp = prevGroup.next;
            prevGroup.next = prev;
            prevGroup = tmp;
        }
        return dummy.next;
    }
}
