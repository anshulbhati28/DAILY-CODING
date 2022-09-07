class Solution {
public:
//     vector<vector<int>> memo;
    
//     int solve(vector<vector<int>>& grid,int r,int c){
//         if(r>=grid.size()) return 0;
//         if(memo[r][c+1]!=-1) return memo[r][c+1];
//         int res = INT_MAX;
        
//         for(int i=0;i<grid.size();i++){
//             if(i==c) continue;
//             res = min(res,grid[r][i] + solve(grid,r+1,c));
//         }
//         return memo[r][c+1] = res;
//     }
    
//     int minFallingPathSum(vector<vector<int>>& grid) {
//       memo.assign(grid.size()+1,vector<int>(grid.size()+2,-1));
//       int res = solve(grid,0,-1);
//       return res;
//     }
    
        int dp[201][201];
    int f(vector<vector<int>>& arr, int i, int j) {
        if(i == arr.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = 0; k < arr[0].size(); k++) {
            if(k == j)
                continue;
            int curr = arr[i][j] + f(arr, i + 1, k);
            ans = min(ans, curr);
        }
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int ans = INT_MAX;
        if(arr.size() == 1)
            return arr[0][0];
        memset(dp, -1, sizeof dp);
        for(int j = 0; j < arr[0].size(); j++) {
            ans = min(ans, f(arr, 0, j));
        }
        return ans;
    }
};