class Solution {
public:
    int handler(int num1, int num2, string op) {
        int res;
        if (op == "+") {
            res = num1 + num2;
        } else if (op == "-") {
            res = num1 - num2;
        } else if (op == "*") {
            res = num1 * num2;
        } else {
            res = num1 / num2;
        }
        return res;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> ops = {"+", "-", "*", "/"};
        for (string t : tokens) {
            if (ops.count(t)) {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(handler(num1, num2, t));
            } else {
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};
