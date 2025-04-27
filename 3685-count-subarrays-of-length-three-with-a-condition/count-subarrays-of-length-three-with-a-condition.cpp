class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        for(int i=0;i<n-2;i++){
            int j =i;
            int left = nums[j];
            int right = nums[j+2];
            int mid = nums[j+1];
           
            int sum = left + right;
            if(2*sum == mid){
                count+=1;
            }

        }
        return count;
    }
};