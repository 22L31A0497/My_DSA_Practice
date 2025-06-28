class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      long long int sum=0; 
      for(int i=0;i<k;i++){
        sum+=nums[i];
      } 
      long long maxi=sum;
      
      int i=0;
      int j=k;
      while(j<nums.size()){
        sum+=nums[j];
        sum-=nums[i];
        j++;
        i++;
        maxi=max(sum,maxi);
        
      }
      //return static_cast<double>(maxi) / k;
      return maxi/(double)k;
    }
};