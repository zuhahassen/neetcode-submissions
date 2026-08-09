class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1); 
        
        for (int i = 0; i < m - 1; i++) {
            vector<int> newRow(n, 1); 
            int index = n - 2; 

            while (index >= 0) {
                newRow[index] = newRow[index + 1] + row[index];
                index--;
            }
            row = newRow; 
        }
        return row[0];
    }
};
