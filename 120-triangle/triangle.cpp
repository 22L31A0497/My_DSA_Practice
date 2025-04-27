class Solution {
public:

    int solve(int n,int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i  == n-1)return triangle[i][j];
        int bottom = triangle[i][j]+ solve(n,i+1,j,triangle,dp);
        int diag = triangle[i][j]+solve(n,i+1,j+1,triangle,dp);
        return dp[i][j]= min(bottom,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=0;
        int j=0;
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(n,0,0,triangle,dp);
    }
};