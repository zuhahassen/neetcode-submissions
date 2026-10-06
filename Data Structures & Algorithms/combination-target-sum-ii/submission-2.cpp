class Solution {
public:
    void backtrack (const vector<int>& candidates, int target, int total, int i, vector<int>& combination, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(combination);
            return;
        }
        
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }

            if (total + candidates[j] > target) {
                break;
            }

            combination.push_back(candidates[j]); 
            backtrack(candidates, target, total + candidates[j], j + 1, combination, res); 
            combination.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res; 
        vector<int> combination; 
        backtrack(candidates, target, 0, 0, combination, res);
        return res; 
    }

};
