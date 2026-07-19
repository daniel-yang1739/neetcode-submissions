class Node:
    def __init__(self, key: int, val: int):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:
    
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key_pos = {}
        self.front = self.back = None

    def erase(self, node: Node) -> None:
        if node.prev:
            node.prev.next = node.next
        if node.next:
            node.next.prev = node.prev
        if node == self.front:
            self.front = node.next
        if node == self.back:
            self.back = node.prev
        node.prev = None
        node.next = None
    
    def move_to_front(self, node: Node) -> None:
        if node == self.front:
            return
        if node == self.back:
            self.back = node.prev
        if node.prev:
            node.prev.next = node.next
        if node.next:
            node.next.prev = node.prev
        node.next = self.front
        if self.front:
            self.front.prev = node
        node.prev = None
        self.front = node
        if not self.back:
            self.back = node

    def get(self, key: int) -> int:
        node = self.key_pos.get(key)
        if not node:
            return -1
        self.move_to_front(node)
        return node.val

    def put(self, key: int, value: int) -> None:     
        if node := self.key_pos.get(key):
            node.val = value
            self.move_to_front(node)
            return
        if len(self.key_pos) >= self.capacity:
            del self.key_pos[self.back.key]
            self.erase(self.back)
        node = Node(key, value)
        self.move_to_front(node)
        self.key_pos[key] = node