class Solution {
private:
    unordered_map<int, vector<int>> adj;
    bool validTreeDFS(int node, int parent, unordered_set<int>& visited) {
        if (visited.count(node)) return false;
        visited.insert(node);
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (!validTreeDFS(neighbor, node, visited)) {
                return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        // Adjacent List
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        if (!validTreeDFS(0, -1, visited)) {
            return false;
        }
        return visited.size() == n;
    }
};
