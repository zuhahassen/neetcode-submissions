class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int target, int i) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (target < 0 || i >= nums.size()) {
            return;
        }
 
        subset.push_back(nums[i]);
        helper(nums, res, subset, target - nums[i], i);

        subset.pop_back(); 
        helper(nums, res, subset, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        vector<int> cur; 
        helper(nums, res, cur, target, 0); 
        return res;
    }
};
