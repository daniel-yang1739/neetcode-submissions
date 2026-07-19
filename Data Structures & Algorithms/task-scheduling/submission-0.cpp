class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            ++count[task - 'A'];
        }
        priority_queue<int> max_heap;
        for (int c : count) {
            if (c != 0) {
                max_heap.push(c);
            }
        }
        int cycle = 0;
        queue<pair<int, int>> waiting;
        while (!max_heap.empty() || !waiting.empty()) {
            ++cycle;
            if (max_heap.empty()) {
                cycle = waiting.front().second;
            } else {
                int c = max_heap.top();
                max_heap.pop();
                if (c - 1 > 0) {
                    waiting.push({c - 1, cycle + n});
                }
            }
            if (!waiting.empty() && waiting.front().second == cycle) {
                max_heap.push(waiting.front().first);
                waiting.pop();
            }
        }
        return cycle;
    }
};
