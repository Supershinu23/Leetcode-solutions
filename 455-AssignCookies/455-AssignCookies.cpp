// Last updated: 14/07/2026, 00:54:18
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0 ;
        int r = 0 ;
        int ans  =0 ;
        while(l<g.size() && r< s.size()){
            if(g[l]<=s[r]){
                ans++;
                l++;
            }
            r++;
        }
        return ans;
    }
};