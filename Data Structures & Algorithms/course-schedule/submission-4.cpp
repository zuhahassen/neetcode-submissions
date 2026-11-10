class Solution {
public:
    bool dfs(int crs, unordered_map<int, vector<int>>& preq, unordered_set<int>& visiting, unordered_set<int>& visited) {
        if (visiting.count(crs)) return false; // cycle detected
        if (visited.count(crs)) return true; 

        visiting.insert(crs);

        for (auto pq: preq[crs]) {
            if (!dfs(pq, preq, visiting, visited)) return false; 
        }

        visited.insert(crs);
        visiting.erase(crs);
        return true; 
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preq;
        unordered_set<int> visited; 
        unordered_set<int> visiting; 

        for (auto pq: prerequisites) {
            preq[pq[0]].push_back(pq[1]);
        } 

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, preq, visiting, visited)) return false; 
        }

        return true;
    }
};
