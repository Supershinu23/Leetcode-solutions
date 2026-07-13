// Last updated: 14/07/2026, 00:53:03
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> prevS, nextS;
        int n =arr.size();
        vector<int> prev(n), next(n);
        for(int i=n-1;i>=0;i--){
            while(!nextS.empty() && arr[nextS.top()]>=arr[i])nextS.pop();
            if(!nextS.empty()){next[i]=nextS.top();}
            else{ next[i]=n;}
            nextS.push(i);
        }
        cout<<"1";
        for(int i=0;i<n;i++){
            while(!prevS.empty() && arr[prevS.top()]>arr[i])prevS.pop();
            prev[i] = !prevS.empty() ? prevS.top():-1;
            prevS.push(i);
        }
        cout<<"2";

        long long ans = 0 ;
        for(int i=0;i<n;i++){
            int mod = 1e9+7;
            ans = (ans + (long long)arr[i] * (next[i]-i) * (i-prev[i])) % mod;
        }

        return ans;
    }
};