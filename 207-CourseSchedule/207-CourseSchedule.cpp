// Last updated: 14/07/2026, 00:54:56
class Solution {
public:
    bool dfs(vector<vector<int>> &pre, vector<int> &vis, int i){
        if(vis[i]==1)return false;
        if(vis[i]==2)return true;

        vis[i]=1;
        for(int p: pre[i]){
            if(!dfs(pre, vis, p)){
                return false;
            }
        }
        vis[i]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> vec(numCourses);
        for(auto& t: pre){
            vec[t[0]].push_back(t[1]);
        }
        vector<int> vis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!dfs(vec, vis, i)){
                return false;
            }
        }
        return true;
    }
};