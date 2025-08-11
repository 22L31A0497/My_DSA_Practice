class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: 1 way to make sum 0 (empty subset)
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                // Exclude current element
                dp[i][sum] = dp[i - 1][sum];

                // Include current element if it doesn't exceed sum
                if (arr[i - 1] <= sum) {
                    dp[i][sum] = (dp[i][sum] + dp[i - 1][sum - arr[i - 1]]) % MOD;
                }
            }
        }

        return dp[n][target];
    }
};
