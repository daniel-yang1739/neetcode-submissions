class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Adjacent Min Heap
        unordered_map<
            string, 
            priority_queue<string, vector<string>, greater<>>
        > minHeap;
        for (auto& ticket : tickets) {
            minHeap[ticket[0]].push(ticket[1]);
        }

        stack<string> stk;
        stk.push("JFK");
        vector<string> res;
        while (!stk.empty()) {
            string src = stk.top();
            if (minHeap[src].empty()) {
                res.push_back(src);
                stk.pop();
                continue;
            }
            string dst = minHeap[src].top();
            minHeap[src].pop();
            stk.push(dst);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
