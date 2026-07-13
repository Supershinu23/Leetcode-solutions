// Last updated: 14/07/2026, 00:53:38
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix ;
        int n = nums.size();
        int ans = 0 ;
        int sum = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }

        for(int i=0;i<n;i++){
            if(prefix[i]==k)ans++;

            if(m.find(prefix[i]-k)!=m.end()){
                ans+=m[prefix[i]-k];
            }
            m[prefix[i]]++;
        }
        return ans;



        
    }
};