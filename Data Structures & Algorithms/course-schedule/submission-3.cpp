class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        for (auto preReq : prerequisites) {
            preMap[preReq[0]].push_back(preReq[1]);
        }
        unordered_set<int> path;
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(i, path, preMap)) {
                return false;
            }
        }
        return true;
    }

    bool canFinishDFS(
        int course, 
        unordered_set<int>& path, 
        unordered_map<int, vector<int>>& preMap
    ) {
        if (path.count(course)) {
            return false;
        }
        if (preMap[course].empty()) {
            return true;
        }
        path.insert(course);
        for (int c : preMap[course]) {
            if (!canFinishDFS(c, path, preMap)) {
                return false;
            }
        }
        path.erase(course);
        return true;
    }
};
