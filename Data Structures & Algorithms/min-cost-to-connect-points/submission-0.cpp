class Solution {
public:
    int getCost(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPoints = points.size();
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>, 
            greater<>
        > minHeap;

        for (int i = 1; i < numPoints; ++i) {
            int cost = getCost(points[0], points[i]);
            minHeap.push({cost, 0, i});
        }

        unordered_set<int> visited;
        visited.insert(0);

        int totalCost = 0;
        while (visited.size() < numPoints) {
            const auto [cost, src, dst] = minHeap.top();
            minHeap.pop();

            if (visited.count(dst)) {
                continue;
            }

            totalCost += cost;
            visited.insert(dst);
            for (int i = 0; i < numPoints; ++i) {
                if (visited.count(i)) {
                    continue;
                }
                int edgeCost = getCost(points[dst], points[i]);
                minHeap.push({edgeCost, dst, i});
            }
        }

        return totalCost;
    }
};
