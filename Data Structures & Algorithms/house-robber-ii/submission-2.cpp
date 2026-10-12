class Solution {
public:
    int dp (vector<int>& nums, int index, vector<int>& memo) {
        if (index >= nums.size()) {
            return 0; 
        }

        if (memo[index] != -1) {
            return memo[index];
        }   

        memo[index] = max(dp(nums, index + 1, memo), nums[index] + dp(nums, index + 2, memo));

        return memo[index];
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> memo1(nums.size(), -1);
        vector<int> memo2(nums.size(), -1);

        vector<int> wFront(nums.begin(), nums.end()-1); 
        vector<int> wBack(nums.begin() + 1, nums.end());

        return max (dp(wFront, 0, memo1), dp(wBack, 0, memo2));
    }
};
