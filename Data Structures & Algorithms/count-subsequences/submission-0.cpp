class Solution {
public:
    int dp (string s, string t, int i, int j, vector<vector<int>>& track) {
        if (j >= t.length()) {
            return 1;
        } 
        
        if (i >= s.length()) {
            return 0;
        }

        if (track[i][j] != -1) {
            return track[i][j];
        }

        track[i][j] = dp(s, t, i + 1, j, track);
        if (s[i] == t[j]) {
            track[i][j] += dp(s, t, i + 1, j + 1, track);
        } 

        return track[i][j];
    }   
    int numDistinct(string s, string t) {
        vector<vector<int>>track(s.length(), vector<int>(t.length(), -1));

        return dp(s, t, 0, 0, track);
    }
};
