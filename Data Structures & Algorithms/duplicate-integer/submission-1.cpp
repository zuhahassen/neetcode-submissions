class Solution {
public:
    bool hasDuplicate(vector<int>& nums) { 
        set<int> hold;
        int size = hold.size(); 

        for (int n: nums) {
            hold.insert(n);
            
            if (hold.size() != (size + 1)) {
                return true;
            }

            size = hold.size();
        }
       
        return false;    
    }
};