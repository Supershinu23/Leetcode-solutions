// Last updated: 14/07/2026, 00:55:01
class Solution {
public:
    int func(vector<int>& nums, int i, vector<int> &dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int m = 0 ;
        int j = i+2;
        while(j<nums.size()){
            m = max(m,func(nums,j,dp));
            j++;
        }
        return dp[i]=m+nums[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        // vector<int> dp(n,-1);
        // int ans = func(nums,0, dp);
        // return max(func(nums,0, dp),func(nums,1, dp));

        int prev = nums[n-1];
        int prev2 = nums[n-2];

        for(int i=n-3;i>=0;i--){
            int temp = prev2 ;
            prev2 = max(prev2-nums[i+1], prev)+nums[i];
            prev = temp ;
        }
        return max(prev2, prev);
    }
};