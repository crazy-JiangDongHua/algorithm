class Solution {
private:
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};
    bool dfs(vector<vector<char>>& board, string word, int i, int x, int y){
        if(i==word.length())
            return true;
        board[x][y]*=-1;// visited
        bool res=false;
        for(int j=0;j<dx.size();j++){
            int newx=x+dx[j],newy=y+dy[j];
            if(0<=newx && newx<board.size() && 0<=newy && newy<board.back().size()
                && board[newx][newy]>0 && board[newx][newy]==word[i])
                if(dfs(board, word, i+1, newx, newy)){
                    res=true;
                    break;
                }
        }
        board[x][y]*=-1;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
        for(int j=0;j<board.back().size();j++){
            if(board[i][j]==word[0])
                if(dfs(board, word, 1, i, j))
                    return true;
        }}
        return false;
    }
};