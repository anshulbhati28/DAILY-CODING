class Solution {
public:
    double dp[101][26][26];
    double solve(int n,int k,int i,int j){
        
        if(i<0 || i>=n || j<0 || j>=n) return 0;
        if(k==0) return 1;
        if(dp[k][i][j]) return dp[k][i][j];
        double ans = 0;
        
        ans += solve(n,k-1,i-2,j-1);
        ans += solve(n,k-1,i-1,j-2);
        ans += solve(n,k-1,i+1,j-2);
        ans += solve(n,k-1,i+2,j-1);
        ans += solve(n,k-1,i+2,j+1);
        ans += solve(n,k-1,i+1,j+2);
        ans += solve(n,k-1,i-1,j+2);
        ans += solve(n,k-1,i-2,j+1);
        
        return dp[k][i][j] = ans/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        double ans = solve(n,k,row,column);
        return ans;
    }
};