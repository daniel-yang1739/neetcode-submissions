class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 1;
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visited(wordList.begin(), wordList.end());
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                string front = que.front();
                que.pop();
                if (front == endWord) return length;
                // compare word to check in word list
                for (int j = 0; j < front.length(); ++j) {
                    char curr_c = front[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        front[j] = c;
                        if (visited.count(front)) {
                            que.push(front);
                            visited.erase(front);
                        }
                    }
                    front[j] = curr_c;
                }
            }
            ++length;
        }
        return 0;
    }
};
