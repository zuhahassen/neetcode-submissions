class Solution {
public:
    int dp (vector<vector<int>>& track, string w1, string w2, int i1, int i2) {
        if (i1 == w1.length()) {
            return w2.length() - i2; 
        }

        if (i2 == w2.length()) {
            return w1.length() - i1; 
        }

        if (track[i1][i2] != -1) {
            return track[i1][i2]; 
        }

        if (w1[i1] == w2[i2]) {
            track[i1][i2] = dp(track, w1, w2, i1 + 1, i2 + 1); 
            return track[i1][i2];
        }

        int res = min(dp(track, w1, w2, i1 + 1, i2 + 1), dp(track, w1, w2, i1 + 1, i2));
        res = min(res, dp(track, w1, w2, i1, i2 + 1));

        track[i1][i2] = 1 + res;
        return track[i1][i2];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> track(word1.length(), vector<int>(word2.length(), -1));
        return dp(track, word1, word2, 0, 0); 
    }
};
