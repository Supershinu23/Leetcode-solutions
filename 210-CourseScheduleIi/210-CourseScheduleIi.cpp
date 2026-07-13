// Last updated: 14/07/2026, 00:54:55
class Solution {
public:
bool dfs(vector<vector<int>> &pre, vector<int> &vis, int i, stack<int> &s){
        if(vis[i]==1)return false;
        if(vis[i]==2)return true;

        vis[i]=1;
        for(int p: pre[i]){
            if(!dfs(pre, vis, p,s)){
                return false;
            }
        }
        vis[i]=2;
        s.push(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> vec(numCourses);
        stack<int> s;
        for(auto& t: pre){
            vec[t[0]].push_back(t[1]);
        }
        vector<int> ans;
        vector<int> vis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!dfs(vec, vis, i,s)){
                return ans;
            }
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            ans.push_back(t);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};