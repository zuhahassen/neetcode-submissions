class Solution {
public:
    int dp (string s1, string s2, int i, int j, vector<vector<int>>& track) {

        if (i >= s1.length() || j >= s2.length()) {
            return 0;
        }

        if (track[i][j] != -1) {
            return track[i][j];
        }

        if (s1[i] != s2[j]) {
            track[i][j] = max(dp(s1, s2, i + 1, j, track), dp(s1, s2, i, j + 1, track));
        } else {
            track[i][j] = 1 + dp(s1, s2, i + 1, j + 1, track);
        }
           


        return track[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> track(text1.length(), vector<int>(text2.length(), -1) ); 

        return dp(text1, text2, 0, 0, track);
    }
};
