class Solution{
public:

    string f(string &s, int &i){
        string ans;
        while(i<s,size()){
            if(s[i] == ')'){
                i++;
                reverse(ans.begin(), ans.end());
                return ans;
            }else if(s[i] == '('){
                i++;
                string temp = f(s,i);
                ans += temp;
            }else{
                ans += s[i];
                i++ 
            }
        }
        return ans;
    }
    string reverseParentheses(string s){
        int i = 0;
        return f(s,i);
    }
};
