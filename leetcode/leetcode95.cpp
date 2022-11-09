// 共用内存
class Solution {
private:
    vector<vector<vector<TreeNode* > > > dp;
public:
    vector<TreeNode*> generateTrees(int n) {
        dp.assign(n+2, vector<vector<TreeNode*>>(n+2, vector<TreeNode*>()));
        for(int i=1;i<=n+1;i++){
            dp[i][i].push_back(new TreeNode(i));
            dp[i][i-1].push_back(nullptr);
        }
        for(int l=2;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int j=i+l-1;
                for(int r=i;r<=j;r++){
                    for(auto lc:dp[i][r-1])
                        for(auto rc:dp[r+1][j]){//可能访问dp[n+1][n]
                            dp[i][j].push_back(new TreeNode(r, lc, rc));
                        }
                }
            }
        }
        return dp[1][n];
    }
};



class Solution {
private:
    vector<TreeNode*> gen(int s, int e){
        vector<TreeNode*> res;
        if(s>e){
            res.push_back(nullptr);
            return res;
        }
        for(int i=s;i<=e;i++){
            vector<TreeNode*> lv=gen(s,i-1);
            vector<TreeNode*> rv=gen(i+1,e);
            for(TreeNode*& lc:lv)
                for(TreeNode*& rc:rv){
                    res.push_back(new TreeNode(i, lc, rc));
                }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return gen(1,n);
    }
};