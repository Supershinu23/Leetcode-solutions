// Last updated: 14/07/2026, 00:52:51
class Solution {
public:
    int m, n ;
    vector<int> d = {-1,0,1,0,-1};
    void dfs(vector<vector<int>> &vec, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || vec[i][j]==0)return;
        vec[i][j] = 0 ;
        for(int t=0;t<4;t++){
            dfs(vec, i+d[t], j+d[t+1]);
        }
        }
    int numEnclaves(vector<vector<int>>& board) {
        queue<pair<int, int>> q ;
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            dfs(board, i, 0);
            dfs(board, i, n-1) ;
        }

        for(int i=0;i<n;i++){
            dfs(board, 0, i);
            dfs(board, m-1, i);
        }
        int ans  = 0;
        for(int i=0;i< m;i++){
            for(int j = 0 ;j< n;j++){
                if(board[i][j]==1)ans++;
            }
        }
        return ans;
    }
};