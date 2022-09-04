class Solution {
public:
    const long mod = 1e9+7;
    
    long solve(int n, int k, int target){
        vector<vector<long>> dp(n+1,vector<long>(target+1,0));
        
        dp[0][0] = 1;
        
        for(int d=1;d<=n;d++){
            for(int t=1;t<=target;t++){
                long ans = 0;
                for(int i=1;i<=k;i++){
                    if(t-i>=0)
                    ans += dp[d-1][t-i];
                }
                dp[d][t] = ans%mod;
            }
        }
        return dp[n][target];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);    
    }
};