class Solution {
public:
    bool isMatch(string text, string pattern) {
   int n=pattern.size();
   int m=text.size();
   vector<bool> prev(m+1, false), curr(m+1, false);
    prev[0] = true; //if(i==0 && j==0)  return true;
   for(int j=1; j<=m; j++){
      prev[j] = false;
   }


   for(int i=1;i<=n;i++){
      //curr is the current row's column
      //and that curr's 0th row has to be assigned everytime
      
      bool flag = true;
      for(int ind=1; ind<=i; ind++){
         if (pattern[ind - 1] != '*') {
           flag = false;
           break;
         }
      }
      //for every row
      //you are asssigning the 0th column's value
      curr[0] = flag;

      for(int j=1; j<=m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') curr[j] = prev[j-1];
            else if(pattern[i-1] == '*') curr[j] = prev[j] | curr[j-1];
            else  curr[j] = false;
      }
      prev = curr;
   }
   return prev[m];       
    }
};