class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
       map<int,int>mpp;
       for(int num:nums){
        mpp[num]++;
       }
       for(auto& it : mpp){
        if(it.second>1){
            ans.push_back(it.first);
        }
       }
       return ans;

        
    }
};