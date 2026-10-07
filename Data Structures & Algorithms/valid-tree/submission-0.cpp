class Solution {
public:
    bool dfs (unordered_set<int>& visiting, unordered_map<int, vector<int>>& adj, int node, int parent) {
        if (visiting.count(node)) {
            return false; // duplicate identified
        }

        visiting.insert(node);
        for (int n: adj[node]) {
            if (n == parent) continue;
            if (!dfs(visiting, adj, n, node)) {
                return false; 
            }
        }
        return true; 
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visiting;

        if (!dfs(visiting, adj, 0, -1)) {
            return false; 
        }

        return visiting.size() == n; 
    }
};
