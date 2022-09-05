class Solution {
public:
    const int mod = 1e9+7;
    long dp[501][1001];
    
    long solve(int s,int i, int l){
       if(i==0 && s==0) return 1;
       long temp = 0;
       if(i<0||i>=l||s==0||i>s)
            return 0;
       if(dp[s][i+500]!=-1) return dp[s][i+500];
       temp += solve(s-1,i+1,l);
       temp += solve(s-1,i-1,l);
       temp += solve(s-1,i,l);
       return dp[s][i+500] = temp%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        long ans = solve(steps,0,arrLen);
        return ans%mod;
    }
};