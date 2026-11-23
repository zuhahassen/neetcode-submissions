class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> temps; 

        for (int i = 0; i < (int)temperatures.size(); i++) {
            while (!temps.empty() && temperatures[i] > temps.top().first) {
                auto p = temps.top(); 
                temps.pop(); 

                res[p.second] = i - p.second; 
            }

            temps.push({temperatures[i], i}); 
        }

        return res; 
    }   
};
