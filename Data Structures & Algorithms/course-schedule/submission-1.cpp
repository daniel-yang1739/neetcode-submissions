class Solution {
private:
    unordered_map<int, vector<int>> node_to_nerghbor;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& pre_req : prerequisites) {
            node_to_nerghbor[pre_req[0]].push_back(pre_req[1]);
        }
        for (int c = 0; c < numCourses; ++c) {
            if (!canFinishDFS(c)) return false;
        }
        return true;
    }

    bool canFinishDFS(int course) {
        if (visiting.count(course)) return false;
        if (node_to_nerghbor[course].empty()) return true;
        visiting.insert(course);
        for (int c : node_to_nerghbor[course]) {
            if (!canFinishDFS(c)) return false;
        }
        visiting.erase(course);
        node_to_nerghbor[course].clear();
        return true;
    }
};
