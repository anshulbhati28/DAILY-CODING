class Solution {
public:
    
    int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = f(i-1,j,obstacleGrid,dp);
        int left = f(i,j-1,obstacleGrid,dp);
      return  dp[i][j] = up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }
        
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         vector<int> prev(m,0);
//         for(int i=0;i<n;i++){
//             vector<int> cur(m,0);
//             for(int j=0;j<m;j++){
//                 if(i==0 && j==0) cur[j] = grid[i][j];
//                 else{
//                     int up = grid[i][j];
//                     if(i>0) up += prev[j];
//                     else up += 1e9;
//                     int left = grid[i][j];
//                     if(j>0) left += cur[j-1];
//                     else left += 1e9;
//                     cur[j] = min(up,left);
//                 }   
//             }
//             prev = cur;
//         }
//         return prev[m-1];
//     }
    
    
//      int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//     for(int i=0;i<n;i++){
//         if(i>0 && j>0 && maze[i][j]==-1){
//             dp[i][j]=0;
//             continue;
//           }
//           if(i==0 && j==0){
//               dp[i][j]=1;
//               continue;
//           }
          
//           int up=0;
//           int left = 0;
          
//           if(i>0) 
//             up = dp[i-1][j];
//           if(j>0)
//             left = dp[i][j-1];
//     }
// }
            
//           dp[i][j] = up+left;
//       }
//   }
  
//   return dp[n-1][m-1];
//     }
};