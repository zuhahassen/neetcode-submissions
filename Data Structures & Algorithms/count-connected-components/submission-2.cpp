class DSU {
    public:
        vector<int> parent; 
        vector<int> rank; 

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 1);
            // everyone is a parent of themselves
            for (int i = 0; i < n; i++) {
                parent[i] = i; 
            }
        } 

        int find(int node) {
            int root = node; 

            while (root != parent[root]) {
                root = parent[root];
            }

            int cur = node; 

            while (cur != root) {
                int next = parent[cur];
                parent[cur] = root; 
                cur = next;
            }

            return root; 
        }

        bool UnionSets(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (pu == pv) {
                return false; // share the same parent already -- remove
            }

            // we take the smaller rank so that we don't build further
            // onto a larger tree 
            if (rank[pv] > rank[pu]) {
                swap(pu, pv);
            }
            
            // let the head of smaller tree be the head! 
            parent[pv] = pu; 
            rank[pu] += rank[pv]; // increase the smaller tree 
            return true; 
        }

}; 

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n); 
        int res = n; 

        for(auto& edge: edges) {
            if (dsu.UnionSets(edge[0], edge[1])) {
                res--; 
            }
        }

        return res; 
    }
};
