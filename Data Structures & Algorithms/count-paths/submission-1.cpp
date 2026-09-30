class Solution {
public:
int rec(int i,int j,int m,int n,vector<vector<int>>& dp){
    if(i>=m || j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==m-1 && j==n-1)return 1;
    return dp[i][j]=rec(i+1,j,m,n,dp)+rec(i,j+1,m,n,dp);
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(1000,vector<int>(1000,-1));
        return rec(0,0,m,n,dp);
    }
};
