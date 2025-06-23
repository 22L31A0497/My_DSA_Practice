class Solution {
public:
  bool bins(vector<int>& nums,int tar){
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == tar)return true;
        else if(nums[mid]>tar){
            
            high = mid-1;
        }else{
            low=mid+1;
            
        }
    }return false;
  }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][0]<=target && matrix[i][n-1]>=target){
                return bins(matrix[i],target);
            }
        }
        return false;
    }
};