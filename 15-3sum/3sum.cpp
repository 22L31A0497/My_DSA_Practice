// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>>st;
//         for(int i=0;i<nums.size();i++){
//             set<int>hasset;
//             for(int j=i+1;j<nums.size();j++){
//                int third = -(nums[i]+nums[j]);
//                if(hasset.find(third)!= hasset.end()){
//                 vector<int>temp ={nums[i],nums[j],third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//                }
//                hasset.insert(nums[j]); 
//             }
//         }
//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n-2; i++) {
            if (i < n-2 && i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int j = i+1;
            int k = n-1;

            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j-1])
                        j++;
                    
                } else if (nums[j] + nums[k] > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};