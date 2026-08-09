class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int r = 0; 

        int l = nums.size() - 1; 

        while (l >= r) {

            if (nums[r] == target) {
                return r;
            } else if (nums[l] == target) {
                return l;
            }

            if (nums[l] > target) {
                l--;
            }

            else if (nums[r] < target) {
                r++;
            }

            else if (nums[r] > target) {
                return -1;
            }

        }


        return -1; 
    }
};
