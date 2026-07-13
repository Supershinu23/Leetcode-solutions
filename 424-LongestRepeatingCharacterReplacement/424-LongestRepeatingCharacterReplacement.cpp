// Last updated: 14/07/2026, 00:54:23
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0 , ans = 0 , maxLength = 0, maxi= 0;
        unordered_map<int, int> m;
        int n = s.size();

        while(r<n){
            m[s[r]-'A']++;
            maxi = max(maxi,m[s[r]-'A']);
            int q = (r-l+1) - maxi;
            while(q>k){
                m[s[l]-'A']--;
                maxi = max(maxi,m[s[l]-'A']);
                q = r-l-maxi;
                l++;
            }
            if(q<=k){
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};