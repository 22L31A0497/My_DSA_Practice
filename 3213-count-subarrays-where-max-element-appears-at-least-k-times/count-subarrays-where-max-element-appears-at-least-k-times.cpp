// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int max =0;
//         for(int i=0;i<nums.size();i++){
//           if(nums[i]> max){
//             max = nums[i];
//           }
//         }
//         int ans =0;
//         for(int i=0;i<nums.size();i++){
//             int count =0;
//             for(int j =i;j<nums.size();j++){
                
//                 if(nums[j]== max){
//                     count++;
//                 }
//                 if(count >= k){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElem = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == maxElem) {
                count++;
            }

            // shrink the window until max appears less than k times
            while (count >= k) {
                // all subarrays from current left to end of array starting at 'right' are valid
                ans += nums.size() - right;

                if (nums[left] == maxElem) {
                    count--;
                }
                left++;
            }
        }

        return ans;
    }
};
