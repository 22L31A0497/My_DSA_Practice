// class Solution {
// public:
//     int solve(int i, int j, int m, int n, vector<vector<int>>& a, vector<vector<int>>& dp) {
//         if (j < 0 || j >= n) { // Fix th
//             return 1e9; // Return BIG positive number (because we want to take min)
//         }
//         if (i == 0) return a[0][j];
//         if (dp[i][j] != -1) return dp[i][j];
        
//         int straight = a[i][j] + solve(i-1, j, m, n, a, dp);
//         int left = a[i][j] + solve(i-1, j-1, m, n, a, dp);
//         int right = a[i][j] + solve(i-1, j+1, m, n, a, dp);
        
//         return dp[i][j] = min(straight, min(left, right));
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
        
//         int mini = 1e9;
//         for (int j = 0; j < n; j++) {
//             mini = min(mini, solve(m-1, j, m, n, matrix, dp));
//         }
//         return mini;
//     }
// };
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: first row = same as matrix
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int straight = dp[i-1][j];
                int left = (j-1 >= 0) ? dp[i-1][j-1] : 1e9;
                int right = (j+1 < n) ? dp[i-1][j+1] : 1e9;
                
                dp[i][j] = matrix[i][j] + min({straight, left, right});
            }
        }

        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};
