class Solution {
public:
    int trap(vector<int>& arr) {
//         using namespace std;
//           int n = arr.size();
//       int waterTrapped = 0;
//     for (int i = 0; i < n; i++) {
//      int j = i;
//      int leftMax = 0, rightMax = 0;
//     while (j >= 0) {
//       leftMax = max(leftMax, arr[j]);
//       j--;
//     }
//     j = i;
//     while (j < n) {
//       rightMax = max(rightMax, arr[j]);
//       j++;
//     }
//     waterTrapped += min(leftMax, rightMax) - arr[i];
//   }
//   return waterTrapped;
   
    int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;

}


        
    
};