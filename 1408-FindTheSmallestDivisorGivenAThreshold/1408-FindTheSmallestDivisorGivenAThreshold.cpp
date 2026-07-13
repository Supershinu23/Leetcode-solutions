// Last updated: 14/07/2026, 00:52:41
class Solution {
public:
    int helper(vector<int> &nums, int mid){
        int ans = 0 ;
        for(int i=0;i<nums.size();i++){
            ans += ceil((double)nums[i]/mid);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1 ;
        int r = INT_MIN;

        for(int i=0;i<nums.size();i++){
            r = max(nums[i], r);
        }

        while(r>l){
            int mid = (r+l)/2;
            if(helper(nums, mid) > threshold){
                l=mid+1;
            }else{
                r = mid;
            }
        }
        return l ;
    }
};