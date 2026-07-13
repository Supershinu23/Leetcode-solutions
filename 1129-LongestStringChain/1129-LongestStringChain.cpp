// Last updated: 14/07/2026, 00:52:49
class Solution {
public:
    static bool comp(const string &A, const string &B){
        return B.length()>A.length();
    }
    bool func(string A, string B){
        int i = 0 , j=0;
        // int n = min(A.size(),B.size());
        int maxAll = 1;
        while(i<A.size() && j<B.size()){
            if(A[i]!=B[j]){
                j++;
                maxAll--;
            }else{
                j++;
                i++;
            }
            if(maxAll<0){
                return false;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &A, const string &B) {
                 return A.length() < B.length(); // ascending
             });
        
        int n= words.size();
        int maxi = 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            int j =0;
            while(j<i){
                if(words[j].length()==words[i].length()-1 && func(words[j], words[i])){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
                j++;
            }
            maxi = max(dp[i], maxi);
        }
        for(int i=0;i<words.size();i++){
            cout<<dp[i]<<" ";
        }
        return maxi;
    }
};