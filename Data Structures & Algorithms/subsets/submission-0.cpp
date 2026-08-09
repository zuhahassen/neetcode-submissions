class Solution {
public:
    void subsets_helper(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int index) {
        if (index >= nums.size()) {
            res.push_back(subset);
            return;
        }
        int i = index; 

        subset.push_back(nums[i]);
        subsets_helper(nums, subset, res, i + 1);
        subset.pop_back(); // removes 
        subsets_helper(nums, subset, res, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset; 
        subsets_helper(nums, subset, result, 0);
        return result; 
    }
};
