class solution{
    public:
        bool RotateString(string s, string goal){
            queue<char> q1,q2;

            if(s.size() != goal.size()) return false;

            if(s==goal) return true;

            for(int i=0;i<s.size();i++) //pushing the values from the original string to q1
                q1.push(s[i]);

             for(int i=0;i<s.size();i++) //pushing the values from the targeted string to q2
                q1.push(s[i]);

            int k=goal.size()-1;
                while(k!=0) {//while(k--) also works
                    char ch=q2.front();
                    q2.pop();
                    q2.push(ch);

                    if(q1 == q2)
                    return true;
                    k--;
            }
            return false;
        }
}