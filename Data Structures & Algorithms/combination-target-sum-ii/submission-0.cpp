class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int target, int i) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (i >= nums.size()) {
            return;
        }
 
        subset.push_back(nums[i]);
        helper(nums, res, subset, target - nums[i], i + 1);

        subset.pop_back(); 
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        helper(nums, res, subset, target, i + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> cur; 
        sort(candidates.begin(), candidates.end()); // sorts!
        helper(candidates, res, cur, target, 0);
        return res; 
    }
};
