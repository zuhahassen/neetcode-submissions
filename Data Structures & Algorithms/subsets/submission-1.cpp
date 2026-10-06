class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int> add, vector<vector<int>>& res) {

        if (index == nums.size()) {
            res.push_back(add);
            add.clear(); 
            return; 
        }

        backtrack(nums, index + 1, add, res); 
        add.push_back(nums[index]);
        backtrack(nums, index + 1, add, res);
        add.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, {}, res);
        return res;
    }
};
