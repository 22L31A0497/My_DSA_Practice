class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int ans=0;
    int sum=0;
    int i=0;
    int j=k;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum>=k*threshold)ans++;
     while(j<arr.size()){
        sum+=arr[j];
        j++;
        sum-=arr[i];
        i++;
        if(sum>= k*threshold)ans++;
     }
   return ans;
    }

};