class Solution {
public:
    const int max = 1e9+7;
    
    long paths(vector<vector<vector<int>>>& dp,int i,int j, int n){
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
        if(n == 1) return 1;
        if(dp[n][i][j]!=-1) return dp[n][i][j];
         long s = paths(dp,i - 1, j - 2, n - 1) % max + // jump to a
            paths(dp,i - 2, j - 1, n - 1) % max + // jump to b
            paths(dp,i - 2, j + 1, n - 1) % max + // jump to c
            paths(dp,i - 1, j + 2, n - 1) % max + // jump to d
            paths(dp,i + 1, j + 2, n - 1) % max + // jump to e
            paths(dp,i + 2, j + 1, n - 1) % max + // jump to f
            paths(dp,i + 2, j - 1, n - 1) % max + // jump to g
            paths(dp,i + 1, j - 2, n - 1) % max; // jump to h
   return dp[n][i][j] = s%max;
    }
    int knightDialer(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(4,vector<int>(3,-1)));
        long s = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                s += paths(dp,i,j,n);
            }
        }
        return s%max;
    }
};