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

    bool union_nodes(int n1, int n2) {
        int root1 = find(n1);
        int root2 = find(n2);
        if (root1 == root2) {
            return false;
        }
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root2] < rank[root1]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            ++rank[root1];
        }
        return true;
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
    int getCost(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() < 2) {
            return 0;
        }
        int numPoints = points.size();
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>, 
            greater<>
        > minHeap;

        for (int i = 0; i < numPoints; ++i) {
            for (int j = i + 1; j < numPoints; ++j) {
                int cost = getCost(points[i], points[j]);
                minHeap.push({cost, i, j});
            }
        }

        UnionFind unionFind(numPoints);
        int totalCost = 0, numEdges = 0;
        while (numEdges != numPoints - 1) {
            if (minHeap.empty()) break;
            const auto [cost, src, dst] = minHeap.top();
            minHeap.pop();
            
            if (!unionFind.union_nodes(src, dst)) {
                continue;
            }

            totalCost += cost;
            ++numEdges;
        }

        return totalCost;
    }
};
