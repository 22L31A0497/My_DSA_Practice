class Solution {
  public:
    // Function to find the length of longest increasing subarray
    int lenOfLongIncSubArr(vector<int> &arr) {
        // Your code goes here.
        int maxi =1;
        int tmax =1;
        if(arr.size()<2)return arr.size();
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                tmax ++;
            }
            else{
                maxi = max(tmax,maxi);
                tmax =1;
            }
        }
       maxi = max(maxi, tmax);
        return maxi;
    }
};