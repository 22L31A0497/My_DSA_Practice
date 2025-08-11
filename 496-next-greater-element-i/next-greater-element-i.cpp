class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        bool marker=false;
        for(int i=0;i<nums1.size();++i){
            for(int j=0;j<nums2.size();++j){
                if(nums2[j]==nums1[i]){
                    marker=true;
                }
                if(marker==true and nums2[j]>nums1[i]){
                    ans.push_back(nums2[j]);
                    marker=false;
                }
                else if(marker==true and j==nums2.size()-1 and nums2[j]<=nums1[i]){
                    ans.push_back(-1);
                    marker=false;
                }
            }
        }
        return ans;
    }
};