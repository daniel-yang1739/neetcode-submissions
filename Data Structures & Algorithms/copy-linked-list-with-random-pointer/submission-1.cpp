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
        if (!head) return NULL;
        unordered_map<Node*, Node*> ori_to_new;
        Node* new_head = new Node(head->val);
        ori_to_new[head] = new_head;
        Node* node = head;  // point to original list
        Node* new_node = new_head;  // point to copied list
        while (node) {
            // Copy the next node of current node
            Node* node_next = NULL;
            if (node->next) {
                if(!ori_to_new.count(node->next)) {
                    node_next = new Node(node->next->val);
                    ori_to_new[node->next] = node_next;
                } else {
                    node_next = ori_to_new[node->next];
                }
            }
            new_node->next = node_next;
            // Copy the random node of current node
            Node* node_random = NULL;
            if (node->random) {
                if (!ori_to_new.count(node->random)) {
                    node_random = new Node(node->random->val);
                    ori_to_new[node->random] = node_random;
                } else {
                    node_random = ori_to_new[node->random];
                }
            }
            new_node->random = node_random;
            node = node->next;
            new_node = new_node->next;
        }
        return new_head;
    }
};
