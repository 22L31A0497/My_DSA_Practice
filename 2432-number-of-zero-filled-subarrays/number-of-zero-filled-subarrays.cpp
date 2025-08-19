class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int count=0;
        int subc =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                subc+=1;
                count+=subc;
            }
            else{
                subc=0;
            }
        }
        return count;

        
    }
};