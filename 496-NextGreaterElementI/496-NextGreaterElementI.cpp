// Last updated: 14/07/2026, 00:54:14
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> v(n);
        int g = nums2[n-1];
        stack<int> s;
        v[n-1] = nums2[n-1];
        s.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty()){
                int t  = s.top();
                if(t>nums2[i])break;
                else s.pop();
            }
            if(!s.empty()){
                v[i] = s.top();
            }else{
                v[i] = nums2[i] ;
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j = 0;j<n;j++){
                if(nums2[j]==nums1[i]){
                    if(v[j]==nums2[j])ans.push_back(-1);
                    else ans.push_back(v[j]);
                }
            }
        }
        return ans;
    }
};