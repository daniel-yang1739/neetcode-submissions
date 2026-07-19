class Solution {
private:
    unordered_map<int, vector<int>> pre_map;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& pre_req : prerequisites) {
            pre_map[pre_req[0]].push_back(pre_req[1]);
        }
        unordered_set<int> path;
        for (int c = 0; c < numCourses; ++c) {
            if (!canFinishDFS(c, path)) {
                return false;
            }
        }
        return true;
    }

    bool canFinishDFS(int course, unordered_set<int>& path) {
        if (path.count(course)) {  // has cycle
            return false;
        }
        if (pre_map[course].empty()) {
            return true;
        }
        path.insert(course);
        for (int c : pre_map[course]) {
            if (!canFinishDFS(c, path)) {
                return false;
            }
        }
        path.erase(course);
        return true;
    }
};
