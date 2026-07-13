// Last updated: 14/07/2026, 00:53:26
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> vec(n+1);
        queue<pair<int,int>> q ;

        for(auto it: times){
            vec[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0 ;
        q.push({k,0});

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int node = p.first;
            int d = p.second;

            for(auto it: vec[node]){
                if(dist[it.first]>it.second+d){
                    dist[it.first] = it.second+d ;
                    q.push({it.first, it.second+d});
                }
            }
        }
        int ans  = INT_MIN ;
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX)return -1;
            cout<<dist[i]<<" ";
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};