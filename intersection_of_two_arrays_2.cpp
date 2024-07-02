class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m; //element:count
        vector<int> ans; //storing the common elements of both of them.
        for(int i=0; i<nums1.size(); i++){
            m[nums1[i]]++;
        }

        for(int i=0; i<nums2.size(); i++){
            auto it = m.find(nums2[i]);
            if(it != m.end() && it->second>0){ //it->second stores the second which has to be greater than 0.
                ans.push_back(nums2[i]);
                it->second--;
            }
        }
        return ans;
    }
};