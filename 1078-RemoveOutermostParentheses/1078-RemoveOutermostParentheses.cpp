// Last updated: 14/07/2026, 00:52:50
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<int> q ;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')q.push(i);
            else{
                int t = q.top();
                q.pop();
                if(q.empty()){
                    cout<<t<<" "<<i<<" ";
                    ans+=s.substr(t+1,i-t-1);
                }
            }
        }
        return ans;
    }
};