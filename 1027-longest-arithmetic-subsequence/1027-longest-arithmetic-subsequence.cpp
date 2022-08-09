class Solution {
public:
    // int longestArithSeqLength(vector<int>& nums) {
    //     int  n = nums.size();
    //     if(n<=2) return n;
    //     vector<unordered_map<int,int>> dp(n);
    //     int max_len = 2;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //         int diff = nums[i] - nums[j];
    //         if(dp[i].find(diff)!=dp[i].end()) {
    //             dp[j][diff] = dp[i][diff] + 1;
    //         }
    //         else dp[j][diff] = 2;
    //             max_len = max(max_len,dp[j][diff]);
    //         }
    //     }
    //     return max_len;
    // }
    
        int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int result = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i]-A[j];
                dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
                result = max(result, dp[i][diff]);
            }
        }
        return result;
    }
};