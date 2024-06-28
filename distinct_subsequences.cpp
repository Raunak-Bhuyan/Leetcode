class Solution {
public:
    int numDistinct(string str, string sub) {
            int n = str.size();
    int m = sub.size();
    vector<double> prev(m+1, 0);
    
    prev[0]  = 1;


    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (str[i - 1] == sub[j - 1]) {
                prev[j] = prev[j - 1] + prev[j];
            }
            
        }
      
    }
    return (int)prev[m];
    }
};