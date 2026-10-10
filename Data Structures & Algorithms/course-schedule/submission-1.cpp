class Solution {
public:
    bool dfs(int crs, unordered_set<int>& visited, unordered_map<int, vector<int>>& preq) {
        if (visited.count(crs)) {
            return false; // cycle detection 
        }

        if (preq[crs].empty()) {
            return true; 
        }

        visited.insert(crs);
        for (int pre: preq[crs]) {
            if (!dfs(pre, visited, preq)) {
                return false;
            }
        }

        visited.erase(crs);
        preq[crs].clear(); 
        return true; 
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preq; 
        unordered_set<int> visited; 

        for (int i = 0; i < numCourses; i++) {
            preq[i] = {};
        }

        for (const auto& prereq: prerequisites) {
            preq[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c, visited, preq)) {
                return false;
            }
        }

        return true; 
    }
};
