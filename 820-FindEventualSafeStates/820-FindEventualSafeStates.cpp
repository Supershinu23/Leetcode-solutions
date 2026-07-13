// Last updated: 14/07/2026, 00:53:12
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
    vector<int> eventualSafeNodes(vector<vector<int>>& vec) {
        int numCourses = vec.size();
        vector<int> vis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                dfs(vec, vis, i);
            }
        }
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};