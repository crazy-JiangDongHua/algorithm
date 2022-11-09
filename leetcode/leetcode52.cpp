class Solution {
private:
    vector<int> colums={0,1,2,3,4,5,6,7,8}; //dfs搜索列
    unordered_set<int> phash; //记录当前棋子的对角线特征，加快判定是否违法
    unordered_set<int> nhash; //记录当前棋子的反对角线特征，加速判定是否违反
    int res=0;
    void dfs(int i, int n){
        if(i==n){
            res++;
        }
        for(int j=i;j<n;j++){
            swap(colums[i], colums[j]);
            // 检查是否冲突
            if(!phash.count(i-colums[i]) && !nhash.count(i+colums[i])){//不冲突
                phash.insert(i-colums[i]);
                nhash.insert(i+colums[i]);
                dfs(i+1, n);
                phash.erase(i-colums[i]);
                nhash.erase(i+colums[i]);
            }
            swap(colums[i], colums[j]);
        }
    }
public:
    int totalNQueens(int n) {
        dfs(0,n);
        return res;
    }
};