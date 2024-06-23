class Solution {
public:
    int helper(int ind, int n, int free, vector<int>& prices, vector<vector<int>> &dp){
        // Base Case
        if(ind >= n) return 0;
        
        if(dp[ind][free] != -1) return dp[ind][free];
        
        //Pick
        int pick = helper(ind+1, n, ind+1, prices, dp) + prices[ind];
        
        
        // Else - Free
        int notpick = INT_MAX;
        if(free){
            notpick = helper(ind+1, n, free-1, prices, dp);
        }
        
        return dp[ind][free] = min(pick, notpick);
        
    }
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (1e5, -1));
        return helper(0, n, 0, prices,dp);
    }
};