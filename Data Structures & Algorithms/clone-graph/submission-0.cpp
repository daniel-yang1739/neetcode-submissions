/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> old_to_new;
        queue<Node*> que;
        que.push(node);
        old_to_new[node] = new Node(node->val);
        while(!que.empty()) {
            Node* front = que.front();
            que.pop();
            Node* new_front = old_to_new[front];
            for (auto neighbor : front->neighbors) {
                Node* new_neighbor;
                if (old_to_new.find(neighbor) == old_to_new.end()) {
                    que.push(neighbor);
                    new_neighbor = new Node(neighbor->val);
                    old_to_new[neighbor] = new_neighbor;
                } else {
                    new_neighbor = old_to_new[neighbor];
                }
                new_front->neighbors.push_back(new_neighbor);
            }
        }
        return old_to_new[node];
    }
};
