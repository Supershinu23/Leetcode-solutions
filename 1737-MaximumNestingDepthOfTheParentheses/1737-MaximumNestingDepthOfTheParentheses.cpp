// Last updated: 14/07/2026, 00:52:29
class Solution {
public:
    int maxDepth(string s) {
        stack<int> st ;
        int ans = 0 ;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            if(s[i]==')'){
                int size = st.size();
                ans = max(size, ans);
                st.pop();
            }
        }
        return ans;
    }
};