// Last updated: 14/07/2026, 00:54:40
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        int row = 0 ;
        int col = n-1;
        
        while(row<m && col>=0){
            if(matrix[row][col] == target){
                return true;
            }

            if(matrix[row][col] > target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};