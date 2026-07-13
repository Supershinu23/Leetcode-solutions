// Last updated: 14/07/2026, 00:54:20
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int> m;
        string ans = "";
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        sort(s.begin(),s.end(),[&](auto &a, auto &b){
            if(m[a]==m[b])return a>b;
            return m[a]>m[b];
        });
        return s;
    }
};