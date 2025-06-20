class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int rep = nums.size()/2;
        map<int,int>mpp;
        for(int val:nums){
            mpp[val]++;
        }
        // for(int i=0;i<nums.size();i++){
        //     if(mpp[nums[i]]>rep)return nums[i];
        // }
        for(const auto it:mpp){
            if(it.second > rep)return it.first;
        }
        return 0;
    }
};