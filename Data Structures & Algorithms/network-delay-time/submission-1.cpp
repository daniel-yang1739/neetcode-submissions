class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adj list
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (const auto& time : times) {
            adjList[time[0]].push_back({time[2], time[1]});
        }

        // Dijkstra's Algo
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>
        > minHeap;
        int maxShortest = 0;
        unordered_map<int, int> shortest;
        minHeap.push({0, k});
        while (!minHeap.empty()) {
            auto [w, target] = minHeap.top();
            minHeap.pop();
            if (shortest.count(target) > 0) {
                continue;
            }
            shortest[target] = w;
            maxShortest = max(maxShortest, shortest[target]);
            for (const auto& [wNext, next] : adjList[target]) {
                minHeap.push({w + wNext, next});
            }
        }
        return shortest.size() == n ? maxShortest : -1;
    }
};
