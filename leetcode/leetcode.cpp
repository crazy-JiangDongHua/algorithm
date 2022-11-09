class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0]=true;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    if(i>0)
                        dp[i][j]=dp[i][j-1]||dp[i-1][j];
                    else
                        dp[i][j]=dp[i][j-1];
                }else{
                    if(i!=0 && (p[j-1]=='?' || s[i-1]==p[j-1]))
                        dp[i][j]=dp[i-1][j-1];
                    else
                        dp[i][j]=false;
                }
            }
        }
        return dp[m][n];
    }
};