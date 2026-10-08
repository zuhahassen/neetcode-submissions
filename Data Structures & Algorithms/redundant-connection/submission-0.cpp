class DSU {
    public: 
        vector<int> parent; 
        vector<int> rank;

        DSU(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 1); 

            for (int i = 0; i <= n; i++) {
                parent[i] = i; 
            }
        }

        int find (int a) {
            int root = a;

            while (root != parent[root]) {
                root = parent[root];
            }

            while (a != root) {
                int next = parent[a]; 
                parent[a] = root; 
                a = next; 
            }

            return root; 
        }

        bool unionSet(int a, int b) {
            int pa = find(a);
            int pb = find(b); 

            if (pa == pb) {
                return false; 
            }

            if (rank[pa] < rank[pb]) {
                swap(pa, pb);
            }

            parent[pb] = pa;
            rank[pa] += rank[pb];

            return true; 
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        DSU dsu(n); 

        for (auto& edge: edges) {
            if (!dsu.unionSet(edge[0], edge[1])) {
                return edge; 
            }
        }

        return {}; 
    }
};
