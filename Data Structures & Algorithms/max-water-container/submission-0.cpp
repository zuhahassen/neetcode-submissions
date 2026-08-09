class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = heights[0] * 0; 
        
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {

                int area = (j - i) * min(heights[i], heights[j]);

                if (max_area < area) {
                    max_area = area; 
                }
            }
        }

        return max_area;
    }
};
