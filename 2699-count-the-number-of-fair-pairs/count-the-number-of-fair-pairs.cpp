class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // long long count = 0;
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         long long sum = (long long)nums[i] + nums[j];
        //         if (sum >= lower && sum <= upper) {
        //             count++;
        //         }
        //     }
        // }
        // return count;
        sort(nums.begin(),nums.end());
        return calc(nums,upper+1)-calc(nums,lower);

    }
    long long calc(vector<int>& nums, int val){
        int left=0,right=nums.size()-1;
        long long res=0;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum<val){
                res+=(right-left);
                left++;
            }
            else{
                right --;
            }
        }
        return res;
    }
};
