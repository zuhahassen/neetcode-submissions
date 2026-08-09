class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq; 
        vector<vector<string>> result; 

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            freq[s].push_back(strs[i]);
        }
        
        for (auto& st: freq) {
            result.push_back(st.second);
        }

        sort(result.begin(), result.end()); 

        return result;
    }
};
