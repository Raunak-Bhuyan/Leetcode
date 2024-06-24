class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the two ends of the rod to the cuts list
        cuts.push_back(0);
        cuts.push_back(n);
        
        // Sort the cuts array
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        // Create a DP table to store the minimum costs
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        // Fill the DP table
        for (int length = 2; length < m; ++length) {
            for (int i = 0; i < m - length; ++i) {
                int j = i + length;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        
        // Return the minimum cost to cut the rod from start to end
        return dp[0][m - 1];
    }
};
