class Solution {
public:
    int f(int i,int j,int m,vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = matrix[i][j] + f(i-1,j,m,matrix,dp);
        int ld = matrix[i][j] + f(i-1,j-1,m,matrix,dp);
        int rd = matrix[i][j] + f(i-1,j+1,m,matrix,dp);
        
        return dp[i][j] = min(up,min(ld,rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int j=0;j<m;j++){
            int ans = f(n-1,j,m,matrix,dp);
            mini = min(mini,ans);
        }
        return mini;
    }
};