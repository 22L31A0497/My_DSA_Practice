class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        vector<int>ans;
        sort(arr.begin(),arr.end());
        int low =0;
        int high = arr.size()-1;
        while(low<=high){
            if(low==high){
              ans.push_back(arr[high]);  
            }
            else{
               ans.push_back(arr[high]);
            ans.push_back(arr[low]);
            }
                
            low++;
            high--;
        }
        return ans;
    }
};
