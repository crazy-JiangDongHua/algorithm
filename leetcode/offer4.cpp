class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)return false;
        int n=matrix[0].size();
        if(n==0)return false;
        int row=0, col=n-1;
        while(row<m && 0<=col){
            if(target==matrix[row][col]){
                return true;
            }else if(target<matrix[row][col]){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};