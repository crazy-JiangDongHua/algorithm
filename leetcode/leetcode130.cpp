class Solution {
private:
    enum State {x, unvisted, visited};
    vector<pair<int,int>> offsets={{0,1},{1,0},{0,-1},{-1,0}};
    void bfs(vector<vector<char>>& board, pair<int,int>& start){
        int m=board.size(), n=board.back().size();
        queue<pair<int,int>> q;
        q.emplace(start);
        board[start.first][start.second]='#';
        while(!q.empty()){
            pair<int, int> f=q.front();q.pop();
            for(pair<int,int>& offset:offsets){
                pair<int,int> c;
                c.first=f.first+offset.first;
                c.second=f.second+offset.second;
                if(0<=c.first && c.first<m && 0<=c.second && c.second<n &&
                    board[c.first][c.second]=='O'){
                    q.emplace(c);
                    board[c.first][c.second]='#';
                }
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board.back().size();
        if(m<2 || n<2)return;
        pair<int,int> start;
        for(int i=0;i<m;i++){
            start.first=i;
            start.second=0;
            if(board[start.first][start.second]=='O')
                bfs(board, start);
            start.second=n-1;
            if(board[start.first][start.second]=='O')
                bfs(board, start);
        }
        for(int j=0;j<n;j++){
            start.first=0;
            start.second=j;
            if(board[start.first][start.second]=='O')
                bfs(board, start);
            start.first=m-1;
            if(board[start.first][start.second]=='O')
                bfs(board, start);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        return;
    }
};