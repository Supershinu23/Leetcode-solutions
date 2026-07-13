// Last updated: 14/07/2026, 00:54:32
class Solution {
public:
    
    int coinChange(vector<int>& nums, int amount) {
        int n = nums.size();
        vector<int> curr(amount+1, 1e9), prev(amount+1, 1e9) ;
        for(int i=0;i<=amount;i++){
            if(i%nums[0]==0){
                prev[i] = i/nums[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake = prev[j];
                int take = 1e9;
                if(j>=nums[i]){
                    take = 1+curr[j-nums[i]];
                }
                curr[j]=min(take, notTake) ;
            }
            prev = curr;
        }
        
        return prev[amount]>=1e9 ? -1 : prev[amount];
    }
};