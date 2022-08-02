class Solution {
public:
//         int cs(vector<int>& nums, int target,vector<int>& dp){
//         if(dp[target]>-1) return dp[target];
//         int count = 0;
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]<=target)
//             count += cs(nums,target-nums[i],dp);
//         }
//         dp[target] = count;
//         return count;
//     }
    
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int> dp(target+1,-1);
//         dp[0] = 1;
//         cs(nums,target,dp);
//         return dp[target];
//     }    

    int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target+1);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i - nums[j] >= 0) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
    }
};