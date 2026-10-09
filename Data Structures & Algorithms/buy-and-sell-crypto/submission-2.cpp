class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0; 

        int buy = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            max_profit = max(prices[i] - buy, max_profit); 
            buy = min(buy, prices[i]);
        }   

        

        return max_profit; 
        
    }
};
