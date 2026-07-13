// Last updated: 14/07/2026, 00:54:47
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0 ;
        int cnt2 = 0 ;
        int maj1 = INT_MIN;
        int maj2 = INT_MIN;

        int n =nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==maj1)cnt1++;
            else if(nums[i]==maj2)cnt2++;
            else if(cnt1==0){
                cnt1++;
                maj1 = nums[i];
            }else if(cnt2==0){
                cnt2++;
                maj2 =nums[i];
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans ;
        cnt1 = 0 ; 
        cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj1)cnt1++;
            if(nums[i]==maj2)cnt2++;
        }
        if(cnt1>n/3){
            ans.push_back(maj1);
        }
        if(cnt2>n/3){
            ans.push_back(maj2);
        }

        return ans;
    }
};