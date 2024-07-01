class Solution {
public:
    int maxProfit(vector<int>& values, int fee) {
    int n = values.size();
    long profit = 0;
    long aheadNotBuy = 0, aheadBuy = 0;
    long currBuy, currNotBuy;
    vector<vector<long>> dp(n+1, vector<long> (2, 0));
    aheadNotBuy = aheadBuy = 0;
        for(int ind = n-1; ind>=0; ind--){

            currBuy = max(-values[ind] + aheadNotBuy,
                     0 + aheadBuy);
                
            currNotBuy = max(values[ind] - fee + aheadBuy, 
                     0 + aheadNotBuy);
                               
            
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};