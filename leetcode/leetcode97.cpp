class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        if(s1.length()<s2.length())
            return isInterleave(s2,s1,s3);
        // 滚动数组 
        vector<bool> dp(s2.length()+1, true);
        for(int i=1;i<=s2.length();i++)
            dp[i]=s2[i-1]==s3[i-1]&&dp[i-1]; 
        for(int i=1;i<=s1.length();i++){
            dp[0]=s1[i-1]==s3[i-1]&&dp[0];
            for(int j=1;j<=s2.length();j++){
                dp[j]= s1[i-1]==s3[i+j-1]&&dp[j]
                     ||s2[j-1]==s3[i+j-1]&&dp[j-1];
                }
            }
        return dp[s2.length()];
    }
};