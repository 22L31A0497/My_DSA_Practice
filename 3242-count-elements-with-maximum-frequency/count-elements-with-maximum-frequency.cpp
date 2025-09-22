class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int max=0;
        for(auto it:mpp){
          if(it.second > max){
            max = it.second;
          }
        }
        int total=0;
        for(auto it:mpp){
            if(it.second == max){
                total += it.second;
            }
        }
        return total;
    }
};