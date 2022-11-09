class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dp(s.length()+1, vector<string>());
        dp[0].emplace_back("");
        for(int i=1;i<=s.length();i++){
            for(string& str:wordDict){
                if(i>=str.length() && !dp[i-str.length()].empty() && s.substr(i-str.length(), str.length())==str){
                    if(i-str.length()==0){
                        dp[i].emplace_back(str);
                    }else{
                        for(string& seq:dp[i-str.length()]){
                            dp[i].emplace_back(seq+" "+str);
                        }
                    }
                }
            }
        }
        return dp[s.length()];
    }
};