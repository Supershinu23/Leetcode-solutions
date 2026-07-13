// Last updated: 14/07/2026, 00:53:00
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            vector<int> temp(n,INT_MAX);
            for(int j = 0;j<n;j++){
                int prev = INT_MAX ; 
                int next = INT_MAX ;
                int curr = dp[j];

                if(i==0){
                    dp[j]= matrix[i][j];
                    continue;
                }
                if(j-1>=0){
                    prev = dp[j-1];
                }
                if(j+1<n){
                    next = dp[j+1];
                }
                temp[j] = matrix[i][j]+ min(curr, min(prev,next));    
            }
            if(i!=0)dp = temp;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[i]);
        }
        return ans;

    }
};