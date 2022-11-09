class Solution {
private:
    string s;
    string p;
    bool match(const int& i, const int& j){
        if(i==0)
            return false;
        else if(p[j-1]=='.')
            return true;
        return s[i-1]==p[j-1];
    }
public:
    bool isMatch(string s, string p) {
        this->s=s;this->p=p;
        int m=s.length(),n=p.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, false));
        dp[0][0]=true;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    if(match(i, j-1))
                        dp[i][j]=dp[i-1][j]||dp[i][j-2];
                    else
                        dp[i][j]=dp[i][j-2];
                }else{
                    if(match(i, j))
                        dp[i][j]=dp[i-1][j-1];
                    else
                        dp[i][j]=false;
                }
            }
        }
        return dp[m][n];
    }
};