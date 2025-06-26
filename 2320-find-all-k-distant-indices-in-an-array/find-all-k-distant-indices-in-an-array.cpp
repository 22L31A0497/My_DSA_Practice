class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        vector<int>ind;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key)ind.push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            for(int it:ind){
                if(abs(i-it)<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};