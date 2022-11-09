//dfs
class Solution {
private:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(0<=cx&&cx<grid.size()&&0<=cy&&cy<grid[0].size()&&grid[cx][cy]=='1')
                dfs(grid,cx,cy);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int x=0;x<grid.size();x++)
            for(int y=0;y<grid[0].size();y++)
                if(grid[x][y]=='1'){
                    ans++;
                    dfs(grid,x,y);
                }
        return ans;
    }
};

//union find set
class Solution {
private:
    class UFS{
        private:
            vector<int> father;
            int cnt;
        public:
            UFS(vector<vector<char>>& grid){
                int m=grid.size();
                int n=grid[0].size();
                father.assign(m*n, -1);
                cnt=0;
                for(int x=0;x<m;x++)
                    for(int y=0;y<n;y++)
                        if(grid[x][y]=='1'){
                            father[x*n+y]=x*n+y;
                            cnt++;
                        }
            }
            int find(int x){
                return x==father[x]?x:father[x]=find(father[x]);
            }
            void myunion(int x, int y){
                int fx=find(x);
                int fy=find(y);
                if(fx!=fy){
                    father[fx]=fy;
                    cnt--;
                }
            }
            int getCount(){
                return cnt;
            }
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        UFS ufs(grid);
        int m=grid.size();
        int n=grid[0].size();
        for(int x=0;x<m;x++)
            for(int y=0;y<n;y++)
                if(grid[x][y]=='1'){
                    //只需要检查右下就行
                    if(y+1<n && grid[x][y+1]=='1')ufs.myunion(x*n+y, x*n+y+1);
                    if(x+1<m && grid[x+1][y]=='1')ufs.myunion(x*n+y, (x+1)*n+y);
                }
        return ufs.getCount();
    }
};