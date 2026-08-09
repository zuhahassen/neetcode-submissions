class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }

        priority_queue<pair<int, int>> freq; 

        for (int i = 0; i < stones.size(); i++) {
            freq.push({stones[i], i}); // weights -> index 
        }
        
        while (freq.size() > 1) {
            int x = freq.top().first; 
            int x_index = freq.top().second; 
            freq.pop(); 

            int y = freq.top().first;
            int y_index = freq.top().second;  
            freq.pop(); 

            if (x > y) {
                x -= y; 
                freq.push({x, x_index});
            } else if (y > x) {
                y -= x;
                freq.push({y, y_index});
            }
        }

        return freq.size() == 1 ? freq.top().first : 0; 
    }
};