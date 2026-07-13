// Last updated: 14/07/2026, 00:52:59
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // map<int, int> m;
        // int n = nums.size();
        // for(int i=1;i<n;i++){
        //     m[i] = -1;
        // }
        // int lowest = 0, ans=0;

        // for(int i=0;i<n;i++){
        //     if(m[nums[i]]==-1)k--;
        //     m[nums[i]] = i ;
        //     int mini = INT_MAX;
        //     for(auto& it: m){
        //         if(it.second!=-1){
        //             // cout<<it.second<<" ";
        //             mini=min(mini, it.second);
        //         }
        //     }
        //     if(k==0)ans+=(mini-lowest)+1;
        //     if(k<0){
        //         lowest = mini+1;
        //         m[nums[mini]] = -1;
        //         k++;
        //         i--;
        //     }
        //     // cout<<"mini "<<mini<< " for i: "<<i<<" ";
        // }
        // return ans;
        return func(nums,k)-func(nums,k-1);
    }
    int func(vector<int> &v, int k){
        int l =0, r = 0 ;
        int ans= 0 ;
        unordered_map<int, int> m;

        int n =v.size();
        while(r<n){
            m[v[r]]++;
            while(m.size()>k){
                m[v[l]]--;
                if(m[v[l]]==0){
                    m.erase(v[l]);
                }
                l++;
            }
            ans+=(r-l)+1;
            r++;
        }
        return ans;
    }
};