class Solution {
public:

    int check(string s, int p1, int p2, int &start, int &end){
        int count = 0; //it will store the length of the palindromic substring.
        if(p1 == p2) //odd length substring
        {
            count++;
            p1--; //left shifting the 1st pointer by one place
            p2++; //right shifting the 2nd pointer by one place
        }
        while(p1>=0 && p2<s.length()){
            if(s[p1] != s[p2]){
                start = p1+1; //returning to the previous index
                end = p2-1;
                return count;
            }
            else{
                p1--;
                p2++;
                count+=2; //2 more characters have been added to our substring.
            }
        }
        start = p1+1;
        end = p2-1;
        return count;

    }
    string longestPalindrome(string s) {
        int start = -1, end = -1, len = 0;
        int f_s = -1; //final palindrome start
        int f_e = -1; //fnal palindrome end

        for(int i=0; i<s.length(); i++){
            int x = check(s, i, i, start, end); //this check condition will return the longest palindromic substring 
            //that can be found that is of odd length.

            if(x>len){
                len = x;
                f_s = start;
                f_e = end;
            }

            int y = check(s, i, i+1, start, end); //for even length substring

            if(y>len){
                len = y;
                f_s = start;
                f_e = end;
            }


        }
        return s.substr(f_s,f_e-f_s+1);
    }
};