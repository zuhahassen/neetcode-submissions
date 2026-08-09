class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> storeNums; 

        for (int n: nums) {

            if (storeNums.contains(n)) {
                return true;
            } 

            storeNums.insert(n);
            
        }

        return false;
    }
};