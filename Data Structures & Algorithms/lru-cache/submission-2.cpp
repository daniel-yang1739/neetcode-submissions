struct Node {
    pair<int, int> val;
    Node* prev;
    Node* next;

    Node(int first, int second):
        val(make_pair(first, second)),
        prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    Node* front = nullptr;
    Node* back = nullptr;
    unordered_map<int, Node*> key_pos;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void erase(Node* node) {
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == front) front = node->next;
        if (node == back) back = node->prev;
        delete node;
    }

    void moveToFront(Node* node) {
        if (node == front) return;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == back) back = node-> prev;
        node->next = front;
        if (front) front->prev = node;
        node->prev = nullptr;
        front = node;
        if (!back) back = node;
    }
    
    int get(int key) {
        if (!key_pos.count(key)) return -1;
        moveToFront(key_pos[key]);
        return key_pos[key]->val.second;
    }
    
    void put(int key, int value) {
        if (key_pos.count(key) != 0) {
            key_pos[key]->val.second = value;
            moveToFront(key_pos[key]);
            return;
        }
        if (key_pos.size() >= capacity) {
            key_pos.erase(back->val.first);
            erase(back);
        }
        Node* node = new Node(key, value);
        moveToFront(node);
        key_pos[key] = node;
    }
};
