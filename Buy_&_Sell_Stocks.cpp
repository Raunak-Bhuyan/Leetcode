class Solution{
    public:
    int maxProfit(vector<int>& prices){
        int buy = prices[0];
        int profit = 0;
            for(int i=0;i<prices.size();i++){
                if(prices[i] < buy){
                    buy = prices[i];
                }else if(prices[i] - buy > profit){
                    profit = prices[i] - buy;
                }
            }
            return profit;
    }
};

//Striver approach (2nd solution)
class Solution{
public:
    int maxProfit(vector<int> &prices){
    int mini = priecs[0];
    int profit = 0;
    int n=prices.size();
        for(int i=0;i<n; i++){
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
}
