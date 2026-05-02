class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>jagan;
        for(int i =0;i<nums.size()-1;i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target){
               jagan.push_back(i);
               jagan.push_back(j);
                }
            }
        }
        return jagan;

    }
};