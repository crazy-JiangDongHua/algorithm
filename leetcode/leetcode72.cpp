class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for(int i=1;i<=n;i++)
            dp[0][i]=i;
        for(int i=1,k=1;i<=m;i++,k^=1){
            dp[k][0]=dp[k^1][0]+1;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[k][j]=min(min(dp[k][j-1],dp[k^1][j]),dp[k^1][j-1]-1)+1;
                }else{
                    dp[k][j]=min(min(dp[k][j-1],dp[k^1][j]),dp[k^1][j-1])+1;
                }
            }
        }
        return dp[m&1][n];
    }
};