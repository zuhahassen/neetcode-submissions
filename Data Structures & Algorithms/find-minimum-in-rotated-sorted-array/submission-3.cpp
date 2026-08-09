class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int l = 0; 
        int r = nums.size() - 1; 

        while (l < r) {
            int m = (l + r) / 2; 

            if (nums[m] < nums[r]) {
                r = m; 

            } else if (nums[m] > nums[r]) {
                l = m + 1; 
            } else {
                return nums[l];
            }

        }
        
        return nums[l]; 
    }

        
        

};
