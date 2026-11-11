class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; 

    void bfs (vector<vector<int>>& heights, set<vector<int>>& ocean, queue<pair<int, int>>& q) {

        while (!q.empty()) {
            auto coord = q.front();
            int r = coord.first; 
            int c = coord.second; 

            q.pop(); 
            ocean.insert({r, c});

            for (auto dir: directions) {
                int nr = r + dir.first; 
                int nc = c + dir.second; 

                if (nr >= 0  && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean.count({nr, nc}) && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }

            }

        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<vector<int>> pacific; 
        set<vector<int>> atlantic;

        queue<pair<int, int>> pq; 
        queue<pair<int, int>> aq; 

        vector<vector<int>> res;

        for (int c = 0; c < heights[0].size(); c++) {
            pq.push({0, c}); 
            aq.push({heights.size() - 1, c});
        } 

        for (int r = 0; r < heights.size(); r++) {
            pq.push({r, 0}); 
            aq.push({r, heights[0].size() - 1});
        }

        bfs(heights, atlantic, aq);
        bfs(heights, pacific, pq);

        for (auto coord: pacific) {
            if (atlantic.count(coord)) res.push_back(coord);
        }

        return res; 
    }
};
