class Solution {
public:
    bool canTransfer(string str1, string str2) {
        int count = 0;
        for (int i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) ++count;
            if (count > 1) return false;
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 1;
        queue<string> que;
        unordered_set<string> visited;
        que.push(beginWord);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                string front = que.front();
                que.pop();
                if (front == endWord) return length;
                for (string s : wordList) {
                    if (visited.count(s)) continue;
                    if (canTransfer(front, s)) {
                        que.push(s);
                        visited.insert(s);
                    }
                }
            }
            ++length;
        }
        return 0;
    }
};
