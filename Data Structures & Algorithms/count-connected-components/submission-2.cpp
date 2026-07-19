class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    int num_comp;
    UnionFind(int n) {  
        num_comp = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    void union_nodes(int n1, int n2) {
        int root1 = find(n1);
        int root2 = find(n2);
        if (root1 == root2) return;
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            ++rank[root1];
        }
        --num_comp;
    }

    int find(int n) {
        int p = parent[n];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];  // compression
            p = parent[p];
        }
        return p;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind union_find(n);
        for (auto& edge : edges) {
            union_find.union_nodes(edge[0], edge[1]);
        }
        return union_find.num_comp;
    }
};
