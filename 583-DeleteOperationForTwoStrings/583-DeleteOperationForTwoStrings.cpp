// Last updated: 14/07/2026, 00:53:36
class Solution {
public:
int func(int i, int j, string text1, string text2, vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j])return dp[i][j]=1+func(i-1,j-1,text1,text2,dp);
        return dp[i][j] = max(func(i-1,j,text1,text2,dp), func(i,j-1,text1, text2,dp));
}
    int minDistance(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int t =  func(n-1, m-1,text1, text2, dp);
        return n+m-2*t;
    }
};