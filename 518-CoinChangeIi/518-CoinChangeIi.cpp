// Last updated: 14/07/2026, 00:54:08
class Solution {
public:
    int func(int a, vector<int>& coins, int i,vector<vector<int>> &dp ){
        if(a==0)return dp[i][a]=1;
        if(i==0){
            if(a%coins[0]==0)return dp[0][a] = 1;
            return 0;
        }
        if(dp[i][a]!=-1)return dp[i][a];
        int take = 0 ;
        int notTake = func(a, coins, i-1,dp);
        if(a-coins[i]>=0)take = func(a-coins[i],coins,i, dp);
        return dp[i][a] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<double>> dp(n,vector<double>(amount+1,0));
        for(int i=0;i<n;i++)dp[i][0]=1;

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                double take = 0 ;
                double notTake = dp[i-1][j];
                if(j-coins[i]>=0)take = dp[i][j-coins[i]];
                dp[i][j] = take+notTake;
            }
        }
        return (int)dp[n-1][amount];
    }
};