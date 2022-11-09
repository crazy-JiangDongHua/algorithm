// 方法一 dfs+记忆化搜索
class Solution {
public:
    vector<vector<int>> dp;//记忆化搜索
    int dfs(int i, int j){
        if(i<0 || j<0)return 0; //数据非法
        else if(i==0 && j==0)return 1;//到达起点
        else
            return dp[i][j]==0?dp[i][j]=dfs(i-1,j)+dfs(i,j-1):dp[i][j];
    }
    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n,0));
        int res=dfs(m-1,n-1); 
        return res;
    }
};

// 方法二 排列组合
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res=1;
        for(int i=1,j=n;i<m;i++,j++){//C_{m+n-2}^{m-1}
            res=res*j/i;
        }
        return res;
    }
};