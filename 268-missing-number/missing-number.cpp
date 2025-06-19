class Solution {
public:
    int missingNumber(vector<int>& nums) {
    //  int sum = 0;
    //  int n = nums.size();
    //  int summat = n*(n+1)/2;

    //  for(int i =0;i<n;i++){
    //     sum += nums[i];
    //  }
    //  return summat-sum;
    map<int,int>mpp;
    for(int it:nums){
        mpp[it]++;
    }
    // for(const auto it:mpp){
    //     if(it.second == 0){
    //         return it.first;
    //     }
    // }
     for (int i = 0; i <= nums.size(); i++) {
        if (mpp[i] == 0) {
            return i;
        }
    }
    return 0;
    }
};