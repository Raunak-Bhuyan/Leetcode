class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxPerimeter = 0;
        int n=nums.size();
            for(int i=n-1; i>1; i--){
                if(nums[i] < nums[i-1] + nums[i-2]){
                    maxPerimeter = nums[i] + nums[i-1] + nums[i-2];
                    return maxPerimeter;
                }
            }
            return 0;
    }
};