// Last updated: 14/07/2026, 00:52:32
class Solution {
public:
    void func(string s, vector<string> &ans, int n){
        int size = s.size();
        if(size==n){
            ans.push_back(s);
            return ;
        }
        if(size==0 || s[size-1]=='1'){
            func(s+"1",ans,n);
            func(s+"0",ans,n);
        }else{
            func(s+"1",ans,n);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        func("", ans, n);
        return ans;
    }
};