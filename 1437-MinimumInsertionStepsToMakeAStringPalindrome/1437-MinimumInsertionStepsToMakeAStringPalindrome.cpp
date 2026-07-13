// Last updated: 14/07/2026, 00:52:40
class Solution {
public:
    int minInsertions(string s) {
        string text2 = s;
        reverse(s.begin(), s.end());
        string text1 = s;
        int n = text1.size();
        int m=text2.size();
        vector<int> curr(m+1), prev(m+1);
        curr[0]=0;
        prev[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return n-curr[m];
    }
};