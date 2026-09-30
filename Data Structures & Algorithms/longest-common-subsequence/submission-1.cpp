class Solution {
public:
int rec(int i,int j,string st1,string st2,vector<vector<int>>& dp){
    if(i==st1.length() || j==st2.length())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(st1[i]==st2[j]){
        return  dp[i][j] =1+rec(i+1,j+1,st1,st2,dp);
    }
    else return dp[i][j] =max(rec(i+1,j,st1,st2,dp),rec(i,j+1,st1,st2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return rec(0,0,text1,text2,dp);
    }
};
