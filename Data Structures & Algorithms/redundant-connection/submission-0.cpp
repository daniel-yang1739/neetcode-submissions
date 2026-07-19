class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    void union_nodes(
        int n1, int n2, vector<int>& res
    ) {
        int root1 = find(n1);
        int root2 = find(n2);
        if (root1 == root2) {
            res = {n1, n2};
            return;
        }
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root2] < rank[root1]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            ++rank[root1];
        }
    }

    int find(int node) {
        int p = parent[node];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];  // compression
            p = parent[p];
        }
        return p;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        UnionFind union_find(edges.size());
        for (auto& edge : edges) {
            if (res.size()) break;
            union_find.union_nodes(edge[0], edge[1], res);
        }
        return res;
    }
};
