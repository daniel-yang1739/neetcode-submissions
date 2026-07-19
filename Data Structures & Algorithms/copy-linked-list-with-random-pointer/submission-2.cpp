/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> ori_to_new;
        Node* node = head;
        while (node) {
            Node* new_node = new Node(node->val);
            ori_to_new[node] = new_node;
            node = node->next;
        }
        node = head;
        while (node) {
            ori_to_new[node]->next = node->next ? ori_to_new[node->next] : nullptr;
            ori_to_new[node]->random = node->random ? ori_to_new[node->random] : nullptr;
            node = node->next;
        }
        return ori_to_new[head];
    }
};
