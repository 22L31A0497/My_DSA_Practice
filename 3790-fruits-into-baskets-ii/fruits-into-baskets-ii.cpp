class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
      int n = fruits.size();
      int ans=n;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(fruits[i]<=baskets[j]){
             ans--;
                baskets[j]=0;
                break;
            }
        }
      }
      return ans;
    }
};

// class Solution {
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         int n = fruits.size();
//         vector<bool> basketUsed(n, false); // Track which baskets are already used
//         int unplacedCount = 0;
//         for (int i = 0; i < n; i++) {
//             bool placed = false;
            
//             for (int j = 0; j < n; j++) {
//                 // Check if the basket is available and has enough capacity
//                 if (!basketUsed[j] && baskets[j] >= fruits[i]) {
//                     basketUsed[j] = true; // Mark the basket as used
//                     placed = true;
//                     break;
//                 }
//             }
            
//             // If we couldn't place this fruit type
//             if (!placed) {
//                 unplacedCount++;
//             }
//         }
        
//         return unplacedCount;
//     }
// };