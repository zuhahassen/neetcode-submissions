class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string str: strs) {
            string sorted = str; 
            sort(sorted.begin(), sorted.end());

            groups[sorted].push_back(str);
        }

        vector<vector<string>> res; 

        for (auto pair: groups) {
            res.push_back(pair.second);
        }

        return res; 
    }
};
