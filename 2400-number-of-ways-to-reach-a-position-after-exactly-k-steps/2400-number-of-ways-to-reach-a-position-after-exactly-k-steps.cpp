class Solution {
public:
    long dp[3001][1001];
    const int mod = 1e9+7;
    
    long count(int start, int end, int k){
        if(start==end && k==0) return 1;
        if(k==0) return 0;
        
        if(dp[start+1000][k]!=-1) return dp[start+1000][k]; 
        long long a = count(start+1,end,k-1);
        a += count(start-1,end,k-1);
        return dp[start+1000][k] = a%mod; 
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        if(abs(startPos-endPos)>k) return 0;
        
        long ans = count(startPos,endPos,k);
        return ans%mod;
    }
};