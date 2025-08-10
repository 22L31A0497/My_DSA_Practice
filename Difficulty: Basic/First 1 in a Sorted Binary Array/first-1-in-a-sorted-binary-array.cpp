class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        // Your code goes here
        int ans =-1;
        int low =0;
        int n=arr.size();
        int high = n-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(arr[mid]==1){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};