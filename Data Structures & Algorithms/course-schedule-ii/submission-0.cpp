class Solution {
private:
    unordered_map<int, vector<int>> pre_map;
    unordered_set<int> path;
    unordered_set<int> visiting;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& pre_req : prerequisites) {
            pre_map[pre_req[0]].push_back(pre_req[1]);
        }
        vector<int> topoSort;
        for (int c = 0; c < numCourses; ++c) {
            if (!findOrderDFS(c, topoSort)) return {};
        }
        return topoSort;
    }

    bool findOrderDFS(int course, vector<int>& topoSort) {
        if (path.count(course)) return false;
        if (visiting.count(course)) return true;
        path.insert(course);
        visiting.insert(course);
        for (int c : pre_map[course]) {
            if (!findOrderDFS(c, topoSort)) return false;
        }
        path.erase(course);
        topoSort.push_back(course);
        return true;
    }
};
