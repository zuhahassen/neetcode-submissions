class Solution {
public:
    void backtrack (const vector<int>& nums, int j, vector<int>& perm, vector<vector<int>>& res, vector<bool> added) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        if (j >= nums.size()) {
            return; 
        }

        for (int i = 0; i < nums.size(); i++) {
            if (added[i]) continue; 
            perm.push_back(nums[i]);
            added[i] = true; 
            backtrack(nums, j +1, perm, res, added);
            perm.pop_back(); 
            added[i] = false; 
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> perm; 
        vector<bool> added(nums.size(), false);

        backtrack(nums, 0, perm, res, added);
        return res; 
    }
};
