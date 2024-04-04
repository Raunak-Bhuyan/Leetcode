class Solution {
public:
    int minDistanceHelper(string& word1, string& word2, vector<vector<int>>& dp, int i, int j){
       // i and j are index values for word 1 and 2.
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //if first string i.e. word1 is empty
        if(i == 0){
            dp[i][j] = j;
            return j;
        }
        //if second string i.e. word2 is empty
        if(j == 0){
            dp[i][j] = i;
            return i;
        }
        if(word1[i-1] == word2[j-1]){ //if last index characterv is matching.
            dp[i][j] = minDistanceHelper(word1, word2, dp, i-1, j-1);
        }
        else{
            int insertOp = minDistanceHelper(word1, word2, dp, i,j-1);
            int deleteOp = minDistanceHelper(word1, word2, dp, i-1,j);
            int replaceOp = minDistanceHelper(word1, word2, dp, i-1,j-1);
            dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1)); //memoization
        return minDistanceHelper(word1, word2, dp, m,n);
    }
};