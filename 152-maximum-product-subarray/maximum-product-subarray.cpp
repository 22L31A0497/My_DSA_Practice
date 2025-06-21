// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//        int maxi=0;
//        int prod=1;
//        for(int i=0;i<nums.size();i++){
//          prod*=nums[i];
//          maxi=max(prod,maxi);
//          if(prod<=0)prod=1;
//        } 
//        return maxi;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];       // fix: initialize with first element
        int prod = 1;

        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            maxi = max(maxi, prod);
            if (prod == 0) prod = 1; // reset only when prod is 0, not negative
        }

        prod = 1; // reset for backward traversal

        // Also check from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            maxi = max(maxi, prod);
            if (prod == 0) prod = 1;
        }

        return maxi;
    }
};
