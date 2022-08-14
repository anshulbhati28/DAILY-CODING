class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMax(vector<string>& strs, int m, int n,int index,vector<vector<vector<int>>>& dp)
    {
        if(index==strs.size()) return 0;
        if(dp[m][n][index]!=-1) return dp[m][n][index];
        int countzeroes = count(strs[index].begin(),strs[index].end(),'0');
        int countones = count(strs[index].begin(),strs[index].end(),'1');
        
     if(m-countzeroes>=0 && n-countones>=0)
     return dp[m][n][index] = max(1 + findMax(strs,m-countzeroes,n-countones,index+1,dp),findMax(strs,m,n,index+1,dp));
        
        return dp[m][n][index] = findMax(strs,m,n,index+1,dp);
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return findMax(strs,m,n,0,dp);
    }
};