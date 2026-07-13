// Last updated: 14/07/2026, 00:53:35
class Solution {
public:
    int countSubstrings(string s) {
        int count  = 0 ;
        for(int i=0;i<s.length();i++){
            count+=isExpand(s, i, i);
            count+=isExpand(s,i,i+1);
        }
    return count;
    }

    int isExpand(string s, int i, int j){
        int count = 0 ;

        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

};