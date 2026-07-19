class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // Adjacency List
        unordered_map<char, string> adjList;
        unordered_map<char, int> indegree;
        for (string word : words) {
            for (char c : word) {
                if (!adjList.count(c)) {
                    adjList[c] = "";
                    indegree[c] = 0;
                }
            }
        }

        for (int i = 1; i < words.size(); ++i) {
            int curr = 0;
            while (
                curr < words[i - 1].length() && 
                curr < words[i].length()
            ) {
                if (words[i - 1][curr] != words[i][curr]) {
                    adjList[words[i - 1][curr]].push_back(words[i][curr]);
                    ++indegree[words[i][curr]];
                    break;
                }
                ++curr;
            }
            if (
                curr == words[i].length() && 
                curr < words[i - 1].length()
            ) {
                // if prefix is same, the shorter one MUST appear first
                return "";
            }
        }

        queue<char> que;
        for (auto& pair : indegree) {
            if (pair.second == 0) {
                que.push(pair.first);
            }
        }

        string res = "";
        while (!que.empty()) {
            const char curr = que.front();
            que.pop();
            res += curr;
            for (char c : adjList[curr]) {
                --indegree[c];
                if (indegree[c] == 0) {
                    que.push(c);
                }
            }
        }
        
        return res.length() == adjList.size() ? res : "";
    }
};
