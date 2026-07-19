class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency List
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto& flight: flights) {
            adjList[flight[0]].push_back({flight[2], flight[1]});
        }

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>
        > minHeap;
        unordered_set<string> visited;

        minHeap.push({0, 0, src});  // cost, stops, target
        while(!minHeap.empty()) {
            const auto [cost, stops, target] = minHeap.top();
            minHeap.pop();

            if (target == dst) {
                return cost;
            }

            // check the same airport with different visited stops
            string key = to_string(target) + "_" + to_string(stops);
            if (visited.count(key) || stops > k) {
                continue;
            }
            visited.insert(key);
            
            for (auto& [c, next] : adjList[target]) {
                minHeap.push({cost + c, stops + 1, next});
            }
        }

        return -1;
    }
};
