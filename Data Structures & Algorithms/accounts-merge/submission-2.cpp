class Solution {
public:
    unordered_map<string, string> parent;

    string find(const string& email) {
        string p = parent[email];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];  // compression
            p = parent[p];
        }
        return p;
    }

    void unionEmail(string e1, string e2) {
        string root1 = find(e1);
        string root2 = find(e2);
        if (root1 != root2) {
            parent[root2] = root1;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailUser;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                // email to user mapping construction
                if (emailUser.count(account[i])) {
                    continue;
                }
                emailUser[account[i]] = account[0];
                // union-find initialization
                parent[account[i]] = account[i];
            }
        }

        for (auto& account : accounts) {
            for (int i = 1; i < account.size() - 1; ++i) {
                unionEmail(account[i], account[i + 1]);
            }
        }

        unordered_map<string, vector<string>> group;
        for (auto& [email, user] : emailUser) {
            string root = find(email);  // traverse non-duplicated
            group[root].emplace_back(email);
        }

        vector<vector<string>> res;
        for (auto& [root, emails] : group) {
            vector<string> currRes = {emailUser[root]};
            sort(emails.begin(), emails.end());
            currRes.insert(currRes.end(), emails.begin(), emails.end());
            res.emplace_back(currRes);
        }

        return res;
    }
};