// Last updated: 14/07/2026, 00:52:31
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        queue<pair<int,int>> q;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> vec(m, vector<int>(n,INT_MAX));

        vec[0][0]=0;

        q.push({0,0});

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            //top
            if(i-1>=0 && max(vec[i][j],abs(heights[i][j] - heights[i-1][j])) < vec[i-1][j] ){
                vec[i-1][j] = max(vec[i][j],abs(heights[i][j] - heights[i-1][j])) ;
                q.push({i-1, j});
            }

            //down
            if(i+1<m && max(vec[i][j],abs(heights[i][j] - heights[i+1][j])) < vec[i+1][j] ){
                vec[i+1][j] = max(vec[i][j],abs(heights[i][j] - heights[i+1][j])) ;
                q.push({i+1, j});
            }

            //left
            if(j-1>=0 && max(vec[i][j],abs(heights[i][j] - heights[i][j-1])) < vec[i][j-1] ){
                vec[i][j-1] = max(vec[i][j],abs(heights[i][j] - heights[i][j-1])) ;
                q.push({i, j-1});
            }
            if(j+1<n && max(vec[i][j],abs(heights[i][j] - heights[i][j+1])) < vec[i][j+1] ){
                vec[i][j+1] = max(vec[i][j],abs(heights[i][j] - heights[i][j+1])) ;
                q.push({i, j+1});
            }
        }

        return vec[m-1][n-1];
    }
};