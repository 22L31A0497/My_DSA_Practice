class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int o=m-1;
      int t=n-1;
      int a=m+n-1;
      while(t>=0){
        if(o>=0 && nums1[o]>nums2[t]){
            nums1[a]=nums1[o];
            o--;
            a--;
        }else{
            nums1[a]=nums2[t];
            a--;
            t--;
        }
      }
    }
};