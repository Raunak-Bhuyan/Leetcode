#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<int> after(2*k+1,0), curr(2*k+1,0);
    
    for(int ind = n-1; ind>=0; ind--){
        for(int transactionNo=2*k-1; transactionNo >= 0; transactionNo--){
            if(transactionNo%2 == 0){
                 curr[transactionNo] = max(-prices[ind] + after[transactionNo+1],
                    0 + after[transactionNo]);
            } else {
                     curr[transactionNo] = max(prices[ind] + after[transactionNo+1],
                         0 + after[transactionNo]);
                 }            
        }after = curr;
    }
    return after[0]; 
}
