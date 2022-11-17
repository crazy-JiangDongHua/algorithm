// 递归思路
class Solution {
private:
    bool macthCore(string::iterator ss, string::iterator se, string::iterator ps, string::iterator pe){
        if(ps==pe)
            return ss==se;
        if(*(ps+1)=='*'){
            if(*ss==*ps || (*ps=='.' && ss!=se)){
                return macthCore(ss+1, se, ps, pe) || // 匹配一次，停留这个状态
                        macthCore(ss, se, ps+2, pe); //直接跳过这个状态
            }else{
                return macthCore(ss, se, ps+2, pe);
            }
        }
        if(*ss==*ps || (*ps=='.' && ss!=se)){
            return macthCore(ss+1, se, ps+1, pe);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return macthCore(s.begin(), s.end(), p.begin(), p.end());
    }
};

// 备忘录加速
class Solution {
private:
    vector<vector<int>> dp;
    bool macthCore(const string& s, unsigned int i, const string& p, unsigned int j){
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j==p.length())
            return dp[i][j]=i==s.length();
        if(p[j+1]=='*'){
            if(s[i]==p[j] || (p[j]=='.' && i!=s.length())){
                return dp[i][j]=macthCore(s, i+1, p, j) || // 匹配一次，停留这个状态
                                macthCore(s, i, p, j+2); //直接跳过这个状态
            }else{
                return dp[i][j]=macthCore(s, i, p, j+2);
            }
        }
        if(s[i]==p[j] || (p[j]=='.' && i!=s.length())){
            return dp[i][j]=macthCore(s, i+1, p, j+1);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        unsigned int m=s.length(), n=p.length();
        dp.assign(m+1, vector<int>(n+1, -1)); //未定义
        return macthCore(s, 0, p, 0);
    }
};


// 也可以自底向上动态规划，这里dp[i][j]和备忘录方法里面的定义相反，这里是前缀匹配，前者是后缀匹配
class Solution {
public:
    bool isMatch(string s, string p) {
        unsigned int m=s.length(), n=p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0]=true;
        // 第一行 此时s为空
        for(unsigned int j=1;j<=n;j++){
            if(p[j-1]=='*')
                dp[0][j]=dp[0][j-2];
        }
        // 后续行
        for(unsigned int i=1;i<=m;i++){
            for(unsigned int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    if(s[i-1]==p[j-2] || p[j-2]=='.'){
                        dp[i][j]=dp[i][j-2]||dp[i-1][j];
                    }else{
                        dp[i][j]=dp[i][j-2];
                    }
                }
                else if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[m][n];
    }
};