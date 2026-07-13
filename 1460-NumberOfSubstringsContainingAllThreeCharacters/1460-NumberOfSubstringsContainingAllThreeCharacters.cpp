// Last updated: 14/07/2026, 00:52:39
class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b =-1 , c = -1;
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')a=i;
            else if(s[i]=='b')b=i;
            else if(s[i]=='c')c=i;

            if(a!=-1 && b!=-1 && c!= -1){
                ans+=min(a, min(b,c))+1;
            }
        }
        return ans;
    }
};