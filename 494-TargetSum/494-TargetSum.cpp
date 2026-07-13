// Last updated: 14/07/2026, 00:54:16
class Solution {
public:
    int func(int target, vector<int> &nums, int i){
        if(i==0){
            // if(target==nums[0] && -1*nums[i]==target)return 2;
            // else if(target==nums[0] || -1*nums[0]==target)return 1;
            // return 0;
            return (target==nums[0])+(-1*nums[i]==target) ;
        }
        int add = func(target+nums[i], nums, i-1);
        int sub = func(target-nums[i], nums, i-1);

        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return func(target, nums, n-1);
    }
};