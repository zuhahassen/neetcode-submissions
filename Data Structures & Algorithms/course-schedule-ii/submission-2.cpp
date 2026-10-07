class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int crs, unordered_set<int>& visited, vector<int>& path, unordered_set<int>& visit) {
        if (visited.count(crs)) {
            return false; // check for cycles 
        }
        if (visit.count(crs)) {
            return true; 
        }

        visited.insert(crs); // we saw this course 
        vector<int> preq = adj[crs];
        for (int pq: preq) {
            if (!dfs(adj, pq, visited, path, visit)) {
                return false; 
            }
        }

        path.push_back(crs);
        visit.insert(crs);
        visited.erase(crs);
        return true; 
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj; 

        for(auto& preq: prerequisites) {
            adj[preq[0]].push_back(preq[1]);
        }

        unordered_set<int> visited;
        vector<int> path; 
        unordered_set<int> visit;  

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(adj, i, visited, path, visit)) {
                return {}; 
            } 

        }

        return path; 
        
    }
};
