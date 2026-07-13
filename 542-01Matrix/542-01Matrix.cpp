// Last updated: 14/07/2026, 00:54:12
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            
            //top
            if(p.first-1>=0 && mat[p.first-1][p.second]!=0 && dist[p.first-1][p.second] > dist[p.first][p.second]+1){
                dist[p.first-1][p.second] = dist[p.first][p.second]+1;
                q.push({p.first-1, p.second});
            }
            // bottom
                if(p.first+1<m && mat[p.first+1][p.second]!=0 && dist[p.first+1][p.second] > dist[p.first][p.second]+1){
                dist[p.first+1][p.second] = dist[p.first][p.second]+1;
                q.push({p.first+1, p.second});
                }
            //right
                if(p.second-1>=0 && mat[p.first][p.second-1]!=0 && dist[p.first][p.second-1]>dist[p.first][p.second]+1){
                dist[p.first][p.second-1] = dist[p.first][p.second]+1;
                q.push({p.first, p.second-1});
                }


                if(p.second+1<n && mat[p.first][p.second+1]!=0 && dist[p.first][p.second+1] > dist[p.first][p.second]+1){
                dist[p.first][p.second+1] = dist[p.first][p.second]+1;
                q.push({p.first, p.second+1});
            }
        }

        return dist;
    }
};