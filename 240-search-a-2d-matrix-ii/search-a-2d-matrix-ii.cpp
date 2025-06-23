class Solution {
public:
  int bins(vector<int>& nums,int tar){
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == tar)return 1;
        else if(nums[mid]>tar){
            
            high = mid-1;
        }else{
            low=mid+1;
            
        }
    }return 0;
  }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>arr;
        for(int i=0;i<m;i++){
         if(bins(matrix[i],target)){
            return true;
         }
        }
        
            return false;
        
       
    }
};