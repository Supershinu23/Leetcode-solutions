// Last updated: 14/07/2026, 00:53:30
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        int t = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr, sc});

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            image[p.first][p.second] = color;

            //check top element
            if(p.first-1>=0 && image[p.first-1][p.second]==t){
                q.push({p.first-1, p.second});
            }

            //check for bottom element
            if(p.first+1 <m && image[p.first+1][p.second]==t){
                q.push({p.first+1, p.second});
            }

            //check for right
            if(p.second+1<n && image[p.first][p.second+1]==t){
                q.push({p.first, p.second+1});
            }

            //check for left
            if(p.second-1>=0 && image[p.first][p.second-1] == t){
                q.push({p.first, p.second-1});
            }
        }

        return image;
    }
};