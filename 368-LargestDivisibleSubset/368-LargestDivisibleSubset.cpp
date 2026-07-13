// Last updated: 14/07/2026, 00:54:27
class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        int maxi = 1;
        int ptr = 0 ;
        for(int i=0;i<n;i++){
            for(int prev = 0; prev<i;prev++){
                if(nums[i]%nums[prev]==0){
                    dp[i] = max(dp[i], 1+dp[prev]);
                    if(1+dp[prev] >= dp[i]){
                        hash[i] = prev;
                        cout<<"reached ";
                    }
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                ptr = i ;
            }
        }
        for(int i=0;i<n;i++){
            cout<<hash[i]<<" ";
        }
        vector<int> ans ;
        ans.push_back(nums[ptr]);
        while(ptr!=hash[ptr]){
            ans.push_back(nums[hash[ptr]]);
            ptr = hash[ptr];
        }
        return ans;
    }
    
};