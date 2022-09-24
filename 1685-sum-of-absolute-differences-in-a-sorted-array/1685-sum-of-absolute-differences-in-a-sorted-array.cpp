class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto a: nums) sum+=a;
        int lnum = 0;
        int lsum = 0;
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            int rsum = sum - lsum - nums[i];
            int rnum = n - 1 - lnum;
            ans[i] = (nums[i]*lnum - lsum) + (rsum - nums[i]*rnum);
            lnum++;
            lsum += nums[i];
        }
        return ans;
    }
};