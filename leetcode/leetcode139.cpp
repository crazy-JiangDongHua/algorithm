class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++){
            for(string& str:wordDict){
                if(i>=str.length() && dp[i-str.length()] && s.substr(i-str.length(), str.length())==str){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};