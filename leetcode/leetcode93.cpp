class Solution {
private:
    enum State {undefine, valid, unvalid};
    vector<vector<State>> dp;
    vector<string> res;
    string ans;

    State is_valid(string& s, int i, int j){
        if(dp[i][j]!=undefine)return dp[i][j];
        if(s[i]=='0' and j-i+1>1)return dp[i][j]=unvalid;
        int sum=0;
        for(int tmp=i;tmp<=j;tmp++)
            sum=sum*10+(s[tmp]-'0');
        return dp[i][j]=(0<=sum && sum<256)?valid:unvalid;
    }
    
    void dfs(string& s, int i, int n, int cnt){
        if(i==n && cnt==4){
            res.emplace_back(ans.substr(0,ans.length()-1));
            return;
        }
        else if(i==n || cnt==4)return;

        for(int j=i;j<min(i+3,n);j++){//四位数一定不合法
            if(is_valid(s, i, j)==valid){
                ans=ans+s.substr(i,j-i+1)+".";      
                dfs(s, j+1, n, cnt+1);
                ans=ans.substr(0,ans.length()-(j-i+2));
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        dp.assign(n, vector<State>(n, undefine));
        dfs(s, 0, n, 0);
        return res;
    }
};