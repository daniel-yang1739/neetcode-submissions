class Solution {
public:
    struct op {
        bool operator()(pair<int, int> parent, pair<int, int> child) {
            int parent_d = pow(parent.first, 2) + pow(parent.second, 2);
            int child_d = pow(child.first, 2) + pow(child.second, 2);
            // swap when parent distance greater than child disance;
            return parent_d > child_d;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, op> heap;
        for (auto& point : points) {
            heap.push({point[0], point[1]});
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            auto [x, y] = heap.top();
            heap.pop();
            res.push_back({x, y});
        }
        return res;
    }
};
