// Last updated: 14/07/2026, 00:53:17
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, int>> q;
        vector<vector<pair<int,int>>> vec(n);

        for(auto t: flights){
            vec[t[0]].push_back({t[1], t[2]});
        }
        vector<int> prices(n,INT_MAX);
        prices[src] = 0 ;
        q.push({src,0});
        while(!q.empty()){
            queue<pair<int, int>> q1 ;
            if(k<0)break ;
            k--;
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                vector<pair<int, int>> v = vec[p.first];
                
                for(auto it: v){
                    if(prices[it.first]>p.second+it.second){
                        q1.push({it.first, p.second+it.second}) ;
                        prices[it.first] = p.second+it.second ;
                    }
                }
            }
            q = q1 ;
        }
        if(prices[dst]==INT_MAX)return -1 ;
        return prices[dst];
    }
};