class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> track;
        vector<int> store;  

        for (int i = 0; i < numbers.size(); i++) {
            int diff = target - numbers[i]; 

            if (track.find(diff) != track.end()) {
                store.push_back(track[diff] + 1);
                store.push_back(i + 1);
                break; 
            } 

            track[numbers[i]] = i; 
        }

        return store; 
        
    }
};
