class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mpp;
        int k=nums.size()/3;
        vector<int>ans;
        for(int it:nums){
            mpp[it]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]>k){
                if(find(ans.begin(),ans.end(),nums[i])==ans.end()){
                   ans.push_back(nums[i]);
                }
                
               
            }
        }
        return ans;
    }
};