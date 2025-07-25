class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                st.insert(nums[i]);
            }
            else{
                maxi = max(maxi,nums[i]);

            }
        }
        int sum =0;
        for(auto it:st){
            sum+=it;
        }
        if(st.size()==0){
            return maxi;
        }
        else{
            return sum;
        }
    }
};