class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int l = 0;
        int r = nums.size()-1;
            for(int i=n-1;i>=0;i--){
            if(abs(nums[l])<=abs(nums[r])){
                ans[i] = nums[r]*nums[r];
                r--;
            }
            else{
                ans[i] = nums[l]*nums[l];
                l++;
            }
        }
        return ans;
    }
};