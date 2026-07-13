// Last updated: 14/07/2026, 00:52:57
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans = 0 ;
        vector<vector<int>> grid2(m,vector<int>(n,0));
        while(!q.empty()){
            queue<pair<int,int>> q2;
            while(!q.empty()){
                pair<int,int> p = q.front();
                grid2[p.first][p.second]=-1;
                q.pop();
                //search for top
                if(p.first-1 >=0){
                    if(grid2[p.first-1][p.second]!=-1 && grid[p.first-1][p.second]==1){
                        q2.push({p.first-1, p.second});
                        grid2[p.first-1][p.second]=-1;
                    }
                }
                //search for down
                if(p.first+1 <m ){
                    if(grid2[p.first+1][p.second]!=-1 && grid[p.first+1][p.second]==1){
                        q2.push({p.first+1, p.second});
                        grid2[p.first+1][p.second]=-1;
                    }
                }
                //search for left
                if(p.second-1 >=0 ){
                    if(grid2[p.first][p.second-1]!=-1 && grid[p.first][p.second-1]==1){
                        q2.push({p.first, p.second-1});
                        grid2[p.first][p.second-1]=-1;
                    }
                }
                //search for right
                if(p.second+1 <n){
                    if(grid2[p.first][p.second+1]!=-1 && grid[p.first][p.second+1]==1){
                        q2.push({p.first, p.second+1});
                        grid2[p.first][p.second+1]=-1;
                    }
                }
            }
            q = q2;
            ans++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && grid2[i][j]!=-1){
                    return -1;
                }
            }
        }
        if(ans==0)return 0 ;
        return ans-1;
    }
};