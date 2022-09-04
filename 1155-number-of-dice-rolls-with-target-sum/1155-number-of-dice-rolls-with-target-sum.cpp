class Solution {
public:
    
    const int mod = 1e9+7;
    
    long long count(int n,int k, int target,vector<vector<long long>>& dp){
        
        if(n==0 && target==0) return 1;
        if(n<=0 || target<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        
        long long temp = 0;
        
        for(int i=1;i<=k;i++){
            temp += count(n-1,k,target-i,dp);
        }
        
        return dp[n][target] = temp%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        long long ans = count(n,k,target,dp);
        return ans%mod;
    }
};