class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int>tem=nums;
        sort(tem.begin(),tem.end());
        int lar =tem[nums.size()-1];
        int ind = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==lar){
                ind = i;
            }
            else{
                if(2*nums[i]>lar){
                    return -1;
                    break;
                }
            }
        }
        return ind;
    }
};