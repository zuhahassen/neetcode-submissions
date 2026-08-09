class Solution {
public:
    void dfs (int r, int c, vector<vector<char>>& grid) {
        if (r >= grid.size() || c >= grid[0].size() || c < 0 || r < 0 || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0'; 

        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int col = grid[0].size();
        int row = grid.size(); 
        int count = 0; 

        for (int c = 0; c < col; c++) {
            for (int r = 0; r < row; r++) {
                if (grid[r][c] == '1') {
                    dfs(r, c, grid);
                    count++;
                }
            }
        }

        return count; 
    }
};
