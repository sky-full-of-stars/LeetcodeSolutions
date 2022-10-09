class Solution
{
private:
    int buySellUtil(int idx, bool canBuy, vector<int> &prices, vector<vector<int>> &cache)
    {
        if(idx >= prices.size())
        {
            return cache[idx][canBuy] = 0;
        }
        
        if(cache[idx][canBuy] != -1)
        {
            return cache[idx][canBuy];
        }
        
        int profit = 0;
        if(canBuy)
        {
            int profitsWithBuyHere = -prices[idx] + buySellUtil(idx+1, 0, prices, cache);
            int profitsWithHoldHere= 0 + buySellUtil(idx+1, 1, prices, cache);
            
            profit = max(profitsWithBuyHere, profitsWithHoldHere); 
        }
        else
        {   
            int profitsWithSellHere = +prices[idx] + buySellUtil(idx+2, 1, prices, cache);
            int profitsWithHoldHere = 0 + buySellUtil(idx+1, 0, prices, cache);
            
            profit = max(profitsWithSellHere, profitsWithHoldHere);
        }
        
        return cache[idx][canBuy] = profit;
    }
    
public:
    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector< vector<int>> cache(n+2, vector<int>(2, -1));
        return buySellUtil(0, 1, prices, cache);
    }
    
};