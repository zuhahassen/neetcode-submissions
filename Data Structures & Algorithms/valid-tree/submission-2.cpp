class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
         if (edges.size() != n -1) {
            return false; 
        }

        unordered_map<int, vector<int>> adj; 

        unordered_set<int> visited; 

        for (auto& pair: edges) {
            adj[pair[1]].push_back(pair[0]);
            adj[pair[0]].push_back(pair[1]);
        }

        queue<int> q; 
        q.push(0);

        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            visited.insert(node); 

            for (int nei: adj[node]) {
                if (!visited.contains(nei)) {
                    q.push(nei);
                } 
            }
        }

        return visited.size() == n; 
    }
};
