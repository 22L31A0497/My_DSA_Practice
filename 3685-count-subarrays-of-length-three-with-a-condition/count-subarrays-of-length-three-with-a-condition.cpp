class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n-2; i++) {
            int left = nums[i];
            int mid = nums[i+1];
            int right = nums[i+2];
            
            if (2 * (left + right) == mid) {
                count++;
            }
        }
        return count;
    }
};

