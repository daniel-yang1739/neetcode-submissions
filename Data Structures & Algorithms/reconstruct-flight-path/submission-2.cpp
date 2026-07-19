class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.rbegin(), tickets.rend());
        unordered_map<string, vector<string>> adjList;
        for (auto& ticket : tickets) {
            adjList[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res;
        stack<string> stk;
        stk.push("JFK");
        while (!stk.empty()) {
            string src = stk.top();
            if (adjList[src].empty()) {
                res.push_back(src);
                stk.pop();
            } else {
                string dst = adjList[src].back();
                adjList[src].pop_back();
                stk.push(dst);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
