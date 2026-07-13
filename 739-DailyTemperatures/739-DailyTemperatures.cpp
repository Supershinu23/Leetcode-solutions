// Last updated: 14/07/2026, 00:53:27
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n =t.size();
        vector<int> ans(n);
        stack<int> s ;
        ans[n-1] = 0;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && t[s.top()]<=t[i]) s.pop();

            if(!s.empty())ans[i] = s.top()-i;
            else ans[i]=0;

            s.push(i);
        }
        return ans;
    }
};