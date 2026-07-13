// Last updated: 14/07/2026, 00:54:17
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count  =0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                maxi = max(maxi,count);
            }
            else count =0;
        }
        return maxi;
    }
};