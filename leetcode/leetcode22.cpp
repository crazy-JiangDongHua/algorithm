class Solution {
private:
    vector<string> res;
    string ans;

    void dfs(int li, int ri, int n){
        if(li==n && ri==n){
            res.emplace_back(ans);
            return;
        }
        // 添加左括号
        if(li<n){
            ans.push_back('(');
            dfs(li+1,ri,n);
            ans.pop_back();
        }
        // 添加右括号
        if(ri<li){// 任何时候右括号数大于左括号数一定是无效组合，而且li<=n
            ans.push_back(')');
            dfs(li,ri+1,n);
            ans.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return res;
    }
};