// Last updated: 14/07/2026, 00:54:11
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ;
        int r = n-1;

        while(r>=l){
            int mid = (l+r)/2;
            int right, left;
            if(mid+1<n && nums[mid+1]==nums[mid]){
                left = mid;
                right = mid+1;
            }else if(mid-1>=0 && nums[mid-1] ==nums[mid]){
                left = mid-1;
                right = mid;
            }else{
                return nums[mid];
            }

            if((r-right)%2!=0){
                l = right+1;
            }else{
                r = left-1;
            }
        }
        return nums[l];
    }
};