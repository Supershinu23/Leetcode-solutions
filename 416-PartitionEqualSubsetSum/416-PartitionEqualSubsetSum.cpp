// Last updated: 14/07/2026, 00:54:24
class Solution {
public:
    bool func(vector<int> & vec, vector<vector<int>> &dp, int sum, int i){
        if(sum==0)return true;
        if(i==0){
            return vec[i]==sum;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool notTake = func(vec, dp, sum, i-1);

        bool take = false;
        if(sum>=vec[i]){
            take = func(vec, dp, sum-vec[i], i-1);
        }
        return dp[i][sum]=take || notTake ;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        if(totalSum%2==1)return false;
        vector<vector<bool>> dp(n, vector<bool>(totalSum+1, false));
        vector<bool> curr(totalSum+1, false);
        vector<bool> prev(totalSum+1, false);
        for(int i=0;i<n;i++){
            dp[i][0]==true;
        }
        dp[0][nums[0]]=true;
        prev[nums[0]] = true;
        curr[0]=prev[0]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<totalSum/2+1;j++){
                bool notTake =prev[j];

                bool take = false;
                if(j>=nums[i]){
                    take = prev[j-nums[i]];
                }
                curr[j]=take || notTake ;
            }
            prev = curr;
        }
        return prev[totalSum/2];
    }
};