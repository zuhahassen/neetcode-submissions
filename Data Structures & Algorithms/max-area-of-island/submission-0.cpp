class Solution {
public:
    void dfs (vector<vector<int>>& grid, int& area, int r, int c) {
        if (r < 0 || r >= grid.size()) {
            return; 
        }

        if (c < 0 || c >= grid[0].size()) {
            return; 
        }

        if (grid[r][c] == 0) {
            return; 
        } 

        grid[r][c] = 0;
        area++; 

        dfs(grid, area, r + 1, c); 
        dfs(grid, area, r - 1, c); 
        dfs(grid, area, r, c + 1); 
        dfs(grid, area, r, c - 1); 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0; 

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    dfs(grid, area, r, c);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea; 
    }
};
