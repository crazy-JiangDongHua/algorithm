class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0)return 0;
        else if(i==0 && j==0)return 1;
        else if(grid[i][j]==1)return dp[i][j]=0;
        else{
            return dp[i][j]==-1?dp[i][j]=dfs(grid,i-1,j)+dfs(grid,i,j-1):dp[i][j];
        }
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid.back().size();
        dp.assign(m, vector<int>(n,-1));
        int res=dfs(obstacleGrid,m-1,n-1);
        return res;
    }
};