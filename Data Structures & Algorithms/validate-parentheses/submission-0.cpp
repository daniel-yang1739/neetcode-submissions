class Solution {
private:
    unordered_map<char, char> parentheses = {
        {')', '('}, {']', '['}, {'}', '{'}
    };
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (parentheses.find(c) == parentheses.end()) {
                stk.push(c);
            } else {
                if (stk.empty()) return false;
                char open = stk.top();
                if (parentheses[c] != open) return false;
                stk.pop();
            }
        }
        return stk.empty() ? true : false;
    }
};
