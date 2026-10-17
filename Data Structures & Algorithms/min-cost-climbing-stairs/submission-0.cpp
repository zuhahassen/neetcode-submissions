class Solution {
public:
    int dp (vector<int>& cost, vector<int>& track, int index) {
        if (index >= cost.size()) {
            return 0;
        }

        if (track[index] != -1) {
            return track[index];
        }   

        track[index] = cost[index] + min(dp(cost, track, index + 1), dp(cost, track, index + 2));

        return track[index];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> track(cost.size(), -1); 
        return min(dp(cost, track, 0), dp(cost, track, 1));
    }
};
