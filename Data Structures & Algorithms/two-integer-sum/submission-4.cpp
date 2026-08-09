class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // has one pair exactly** - key info 
        // what if I sort the array - least to greatest 
        unordered_map<int, int> freq;
        vector<int> indexes; 

        int diff = 0;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]] = i; 
        }

        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];

            if (freq.count(diff) && freq[diff] != i) {
                indexes.push_back(i);
                indexes.push_back(freq[diff]);
                break;
            }
        }

        sort(indexes.begin(), indexes.end());

        return indexes; 
    }
};
