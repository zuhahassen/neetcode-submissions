class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res; 

        priority_queue<pair<int, vector<int>>> pq; 

        for (auto pt: points) {
            int dist = (pt[1] * pt[1]) + (pt[0] * pt[0]); 
            pq.push({dist, pt}); 

            if (pq.size() > k) pq.pop(); 
        }

        while (!pq.empty()) {
            auto pt = pq.top(); 
            pq.pop(); 

            res.push_back(pt.second); 
        }

        return res; 
    }
};
