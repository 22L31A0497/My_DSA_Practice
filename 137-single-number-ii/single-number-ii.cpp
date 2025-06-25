class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map<int,int>mpp;
       for(int it:nums){
        mpp[it]++;
       } 
       for(const auto it:mpp){
        if(it.second==1)return it.first;
       }
       return 0;
    }
};