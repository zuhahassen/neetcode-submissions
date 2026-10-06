class Solution {
public:
    void backtrack(const vector<int>& nums, int target, int index, vector<int>& combination, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(combination);
            //combination.clear(); 
            return; 
        }
         
        if (target < 0 || index >= nums.size()) {
            return; 
        }

        backtrack(nums, target, index + 1, combination, res);
        combination.push_back(nums[index]); 
        backtrack(nums, target - nums[index], index, combination, res);
        combination.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        vector<int> combination; 
        backtrack(nums, target, 0, combination, res);
        return res; 
    }
};
