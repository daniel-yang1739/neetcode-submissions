// class Node {
//   constructor(val, next = null, random = null) {
//       this.val = val;
//       this.next = next;
//       this.random = random;
//   }
// }

class Solution {
    /**
     * @param {Node} head
     * @return {Node}
     */
    copyRandomList(head) {
        let oriToNew = new Map(), node = head;
        while (node) {
            oriToNew.set(node, new Node(node.val));
            node = node.next;
        }
        node = head;
        while (node) {
            oriToNew.get(node).next = oriToNew.get(node.next) ?? null;
            oriToNew.get(node).random = oriToNew.get(node.random) ?? null;
            node = node.next;
        }
        return oriToNew.get(head) ?? null;
    }
}
