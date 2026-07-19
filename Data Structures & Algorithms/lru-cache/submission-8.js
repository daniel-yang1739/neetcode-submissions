class Node {
    constructor (key, value) {
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    /**
     * @param {number} capacity
     */
    constructor(capacity) {
        this.capacity = capacity;
        this.key_pos = new Map();
        this.front = null;
        this.back = null;
    }

    erase(node) {
        if (node.prev) node.prev.next = node.next;
        if (node.next) node.next.prev = node.prev;
        if (node === this.front) this.front = node.next;
        if (node === this.back) this.back = node.prev;
        node.next = null;
        node.prev = null;
    }

    moveToFront(node) {
        if (node === this.front) return
        if (node === this.back) this.back = node.prev;
        if (node.prev) node.prev.next = node.next;
        if (node.next) node.next.prev = node.prev;
        node.next = this.front;
        if (this.front) this.front.prev = node;
        node.prev = null;
        this.front = node;
        if (!this.back) this.back = node;
    }

    /**
     * @param {number} key
     * @return {number}
     */
    get(key) {
        let node = this.key_pos.get(key);
        if (!node) return -1;
        this.moveToFront(node);
        return node.value;
    }

    /**
     * @param {number} key
     * @param {number} value
     * @return {void}
     */
    put(key, value) {
        let node = this.key_pos.get(key);
        if (node) {
            node.value = value;
            this.moveToFront(node);
            return
        }
        if (this.key_pos.size >= this.capacity) {
            this.key_pos.delete(this.back.key);
            this.erase(this.back);
        }
        node = new Node(key, value);
        this.key_pos.set(key, node);
        this.moveToFront(node);
    }
}
