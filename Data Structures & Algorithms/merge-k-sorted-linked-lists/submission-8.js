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
     * @param {ListNode[]} lists
     * @return {ListNode}
     */
    conquer(list1, list2) {
        let dummy = new ListNode(), node = dummy;
        while (list1 && list2) {
            if (list1.val <= list2.val) {
                node.next = list1;
                list1 = list1.next;
            } else {
                node.next = list2;
                list2 = list2.next;
            }
            node = node.next;
        }
        if (list1) node.next = list1;
        else node.next = list2;
        return dummy.next;
    }

    divide(lists, l, r) {
        if (l > r) return null;
        if (l == r) return lists[l];
        const mid = Math.floor(l + (r - l) / 2);  // avoid overflow
        const left = this.divide(lists, l, mid);
        const right = this.divide(lists, mid + 1, r);
        return this.conquer(left, right);
    }

    mergeKLists(lists) {
        if (!lists) return nullptr;
        return this.divide(lists, 0, lists.length - 1);
    }
}
