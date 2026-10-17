class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q; 

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    //dfs(grid, r, c, 0); 
                    q.push({r, c}); 
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 

        while (!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 

            for (int i = 0; i < 4; i++) {
                int r = row + dir[i].first;
                int c = col + dir[i].second;

                if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1; 
                q.push({r, c});
            }
        }






    }

    void dfs (vector<vector<int>>& grid, int r, int c, int dist) {
        
        if (r < 0 || c < 0|| r >= grid.size() || c >= grid[0].size() || grid[r][c] == -1) {
            return;
        } 

        if (grid[r][c] < dist) {
            return;
        }

        grid[r][c] = dist;

        dfs(grid, r + 1, c, dist + 1); 
        dfs(grid, r - 1, c, dist + 1); 
        dfs(grid, r, c + 1, dist + 1);
        dfs(grid, r, c - 1, dist + 1);
    }
};
