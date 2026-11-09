class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 

        vector<vector<int>> res; 
        res.push_back(intervals[0]); 

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> back = res.back(); 
            vector<int> cur = intervals[i]; 

            if (cur[0] <= back[1]) {
                res[res.size() - 1][1] = max(back[1], cur[1]);
            } else {
               res.push_back(cur);
            }
        }

        return res; 
    }
};
