// Last updated: 14/07/2026, 00:53:01
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal)-func(nums, goal-1);

    }
    int func(vector<int>& nums, int goal){
        if(goal<0)return 0;
        int r = 0, l = 0;
        int n = nums.size();
        int ans = 0 ;
        int sum = 0 ;

        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};