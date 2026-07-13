// Last updated: 14/07/2026, 00:53:40
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> temp(n,0);
        int ans = 0 ;
        for(int i=0;i<n;i++){
            if(temp[i]==0){
                ans++;
                queue<int> q;
                temp[i]=1;
                q.push(i);
                while(!q.empty()){
                    int t = q.front();
                    q.pop();
                    vector<int> vec = isConnected[t];
                    for(int j=0;j<vec.size();j++){
                        if(i!=j && vec[j]==1 && temp[j]==0){
                            q.push(j);
                            temp[j]=1;
                        }
                    }
                }
            }       
        }
        return ans;
    }
};