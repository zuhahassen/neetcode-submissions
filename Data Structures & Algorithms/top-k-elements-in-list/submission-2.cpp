class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq; 
        map<int, vector<int>> freq_vec; 
        vector<int> topK; 

        for (int n: nums) {
            freq[n]++;
        }

        for (auto& pair: freq) {
            freq_vec[pair.second].push_back(pair.first);
        }
        
        //sort(freq_vec.begin(), freq_vec.end(), greater<int>());

        for (auto it = freq_vec.rbegin(); it != freq_vec.rend(); ++it) {
            vector<int>& hold = it->second;
            for (int n : hold) {
                topK.push_back(n);
                if (--k == 0) return topK;
            }
        }


        return topK; 
    }
};
