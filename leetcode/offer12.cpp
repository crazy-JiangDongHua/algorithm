class Solution {
private:
    vector<vector<bool>> visited;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int r,c;
    bool dfs(const vector<vector<char>>& board, const string& word, int x, int y, int k){
        if(k==word.length())
            return true;
        if(0<=x && x<r && 0<=y && y<c && !visited[x][y] && board[x][y]==word[k]){
            k++;
            visited[x][y]=true;
        }
        else 
            return false;
        bool res=false;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(dfs(board, word, newx, newy, k)){
                res=true;
                break;
            }
        }
        visited[x][y]=false;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length()==0)
            return true;
        r=board.size();
        if(r==0)
            return false;
        c=board[0].size();
        if(c==0)
            return false;
        visited.assign(r, vector<bool>(c, false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};