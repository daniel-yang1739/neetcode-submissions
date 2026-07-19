class Solution {
private:
    unordered_map<int, vector<int>> node_to_neighbors;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& edge: prerequisites) {
            node_to_neighbors[edge[0]].push_back(edge[1]);
        }
        for (int c = 0; c < numCourses; ++c) {
            if (!canFinishDFS(c)) {
                return false;
            }
        }
        return true;
    }

    bool canFinishDFS(int course) {
        if (visiting.count(course)) return false;
        if (node_to_neighbors[course].empty()) return true;
        visiting.insert(course);
        for (int neighbor : node_to_neighbors[course]) {
            if (!canFinishDFS(neighbor)) {
                return false;
            }
        }
        visiting.erase(course);
        node_to_neighbors[course].clear();
        return true;
    }
};
