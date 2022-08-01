class Solution {
public:
    int countpaths(int i,int j,int m,int n,vector<vector<int>> &dp){
        if((i==m-1)&&(j==n-1)) return 1;
           if((i>=m) || (j>=n)) return 0; 
        if(dp[i][j]!=-1) return dp[i][j];
           return dp[i][j] = countpaths(i,j+1,m,n,dp) + countpaths(i+1,j,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        int i=0,j=0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countpaths(i,j,m,n,dp);
    }
};