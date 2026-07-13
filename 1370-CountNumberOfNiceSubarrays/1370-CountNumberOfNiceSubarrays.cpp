// Last updated: 14/07/2026, 00:52:43
class Solution {
public:
int numberOfSubarrays1(vector<int>& nums, int k) {
        if(k<0)return 0;
        int count = 0, l=0, r=0, sum=0;
        int n = nums.size();

        while(r<n){
            sum+=(nums[r]%2);
            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarrays1(nums, k)-numberOfSubarrays1(nums,k-1);
        
    }
};