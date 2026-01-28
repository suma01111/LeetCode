class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int profit = 0;
        
        for(int i=1;i<prices.size();i++){
            if(buyPrice > prices[i]){
                buyPrice = prices[i];
            }
            //checks in it iteration
            // profit = max(profit , prices[i]-buyPrice);
            int currProfit = prices[i]-buyPrice;
            if(currProfit>profit) profit = currProfit;
        }
        return profit;
    }
};