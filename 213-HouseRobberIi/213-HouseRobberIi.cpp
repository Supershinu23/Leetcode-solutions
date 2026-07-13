// Last updated: 14/07/2026, 00:54:53
class Solution {
public:
int func(vector<int>& nums, int i, vector<int> &dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int m = 0 ;
        int j = i+2;
        int maxLimit = (i==0?nums.size()-1:nums.size());
        while(j<maxLimit){
            m = max(m,func(nums,j,dp));
            j++;
        }
        return dp[i]=m+nums[i];
    }
int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);

        // vector<int> dp(n,-1);
        // return max(func(nums,0, dp),func(nums,1, dp));
        int prev = nums[n-1];
        int prev2 = nums[n-2];

        for(int i=n-3;i>=1;i--){
            int temp = prev2 ;
            prev2 = max(prev2-nums[i+1], prev)+nums[i];
            prev = temp ;
        }
        int t1 = max(prev2, prev);

        prev = nums[n-2];
        prev2 = nums[n-3];

        for(int i=n-4;i>=0;i--){
            int temp = prev2 ;
            prev2 = max(prev2-nums[i+1], prev)+nums[i];
            prev = temp ;
        }
        int t2 = max(prev2, prev);

        return max(t2,t1);
    }
};