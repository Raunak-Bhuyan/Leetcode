class Solution{
    public:
        int fib(int n){
            if(n == 0) return 0;
            int secondLast = 0;
            int last = 1;
            for(int i=2; i<=n; i++){
                int sum = last + secondLast;
                secondLast = last;
                last = sum;
            }
            return last;
        }
};