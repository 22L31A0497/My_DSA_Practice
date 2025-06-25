class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      vector<int>ans;
      map<int,int>mpp;
      for(int it:nums){
        mpp[it]++;
      }  
      for(const auto it:mpp){
        if(it.second == 1){
            ans.push_back(it.first);
        }
      }
      return ans;
    }
};