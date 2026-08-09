class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> track; 
        for (int num: nums) {

            if (track.count(num) > 0) {
                return true;
            }

            track[num]++;
        }  
        return false; 
        
    }
};