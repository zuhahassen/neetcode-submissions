class Solution {
public:
    int dp (int target, vector<int>& coins, vector<vector<int>>& track, int index) {
        if (target == 0) {
            return 1;
        } else if (target < 0 || index == coins.size()) {
            return 0;
        }

        if (track[target][index] != -1) {
            return track[target][index];
        }

        int take = dp(target - coins[index], coins, track, index);
        int skip = dp(target, coins, track, index + 1);

        return track[target][index] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> track(amount + 1, vector<int>(coins.size(), -1)); 
        return dp(amount, coins, track, 0);
    }
};
