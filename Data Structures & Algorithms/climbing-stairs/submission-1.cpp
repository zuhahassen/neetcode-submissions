class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> memo; 
        memo[1] = 1; 
        memo[2] = 2; 
        return helper(n, memo); 
    }

    int helper(int n, unordered_map<int, int>& memo) {
        if (memo.count(n)) {
            return memo[n];
        }

        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }
};
