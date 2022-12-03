class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)return 0;
        int n=grid[0].size();
        if(n==0)return 0;
        vector<int> dp(n+1,0);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[j]=max(dp[j], dp[j-1])+grid[i-1][j-1];
            }
        }
        return dp[n];
    }
};