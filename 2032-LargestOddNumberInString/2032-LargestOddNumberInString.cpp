// Last updated: 14/07/2026, 00:52:33
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i=n-1;i>=0;i--){
            if((num[i]-48)%2==1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};