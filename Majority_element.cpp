class Solution{
    public: 
        int majorityElement(vector<int>& nums){
            int count = 0, res = 0;
                for(auto nums:nums){
                    if(count == 0)
                        res = num;
                    if( res != nums)
                        count--;
                    else
                        count--;
                    
                }
                return res;
        }
};