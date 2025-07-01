class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=k-1;
        int mindiff=INT_MAX;
        while(j<nums.size()){
            int up = nums[j];
            int low= nums[i];
            mindiff = min(mindiff,up-low);
            i++;
            j++;
        }
        return mindiff;
    }
};