class Solution {
private:
    int m,n,k;
    vector<vector<int>> vis;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int getBitSum(int x){
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    bool check(int x, int y){
        return 0<=x&&x<m&&0<=y&&y<n&&!vis[x][y]&&(getBitSum(x)+getBitSum(y)<=k);
    }
    int dfs(int x, int y){
        int res=1;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(check(newx, newy)){
                vis[newx][newy]=1;
                res+=dfs(newx, newy);
            }
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if(m<=0 || n<=0 || k<0)
            return 0;
        vis.assign(m, vector<int>(n, 0));
        this->m=m;
        this->n=n;
        this->k=k;
        vis[0][0]=1;
        return dfs(0, 0);
    }
};