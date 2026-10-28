class Solution {
public:
    bool dfs(int crs, unordered_map<int, vector<int>>& adj,  unordered_set<int>& visited, unordered_set<int>& visiting) {
        if (visiting.count(crs)) return false; 
        if (visited.count(crs)) return true; 

        visiting.insert(crs);
        for (int i = 0; i < adj[crs].size(); i++) {
            if (!dfs(adj[crs][i], adj, visited, visiting)) {
                return false; 
            }
        }

        visited.insert(crs);
        visiting.erase(crs);
        return true; 
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj; 

        for (auto pq: prerequisites) {
            adj[pq[0]].push_back(pq[1]);
        }

        unordered_set<int> visited; 
        unordered_set<int> visiting; 

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj, visited, visiting)) {
                return false; 
            }
        }

        return true;
    }
};
