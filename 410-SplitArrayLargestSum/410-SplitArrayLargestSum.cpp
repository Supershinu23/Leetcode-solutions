// Last updated: 14/07/2026, 00:54:25
class Solution {
public:

    int helper(vector<int> &nums, int sum){
        int n = nums.size();
        int ans = 1;
        int currSum=0;
        for(int i =0;i<nums.size();i++){
            if(currSum+nums[i] <=sum){
                currSum+=nums[i];
            }else{
                ans++;
                currSum=nums[i];
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN;
        int high = 0;
        for(int i=0;i<nums.size();i++){
            low = max(nums[i],low);
            high+=nums[i];
        }

        while(low<high){
            int mid = (low+high)/2;
            if(helper(nums, mid) > k){
                low=mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};