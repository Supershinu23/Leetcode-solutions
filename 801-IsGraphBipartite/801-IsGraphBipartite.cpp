// Last updated: 14/07/2026, 00:53:19
class Solution {
public:

    bool dfs(int node, int co, vector<int>&color, vector<vector<int>>& graph){
        color[node] = co;
        for(auto it: graph[node]){
            if(color[it]== -1 && !dfs(it, !co, color, graph)){
                return false;
            }else if(color[it]==co)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !dfs(i, 0, color, graph)){
                return false;
            }
        }
        return true;
    }
};