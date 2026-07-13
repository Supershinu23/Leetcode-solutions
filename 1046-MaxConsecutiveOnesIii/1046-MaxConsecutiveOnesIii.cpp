// Last updated: 14/07/2026, 00:52:53
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r = 0, l =0 ;
        int n = nums.size();
        int len = 0 ;
        while(r<n){
            if(nums[r]==0)k--;
            if(k<0){
                if(nums[l]==0)k++;
                l++;
            }else{
                len = max(len, r-l+1);
            }   
            r++;

        }
        return len;
    }
};