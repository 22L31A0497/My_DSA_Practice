class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count =0;
        // int start= 0;
        // int end =0;
        
        // while(start <nums.size()-1){
        //   end =start+1;
        //   while(end <nums.size()){
        //     if(nums[start]==nums[end]&& (start*end)%k==0){
        //         count += 1;
        //     }
        //     end++;
        //   }
        //   start++;

        // }
        for(int i=0;i<nums.size()-1;i++){
            int j=i+1;
            while(j<nums.size()){
                if(nums[i]==nums[j]&&(i*j)%k==0){
                    count+=1;
                }
                j++;
            }
        }
        return count;
    }
};