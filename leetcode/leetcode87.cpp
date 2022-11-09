class Solution {
private:
    string s1;
    string s2;
    int dp[30][30][31];//0表示未定义，1表示可以互为扰乱，-1表示不可以
    bool check(int i, int j, int len){ //检查两个字符串的字符是否相同，剪枝
        unordered_map<int,int> ht;
        for(int k=i;k<i+len;k++)
            ht[s1[k]]+=1;
        for(int k=j;k<j+len;k++)å
            ht[s2[k]]-=1;
        for(auto& item:ht)
            if(item.second!=0)
                return false;
        return true;
    }
    bool dfs(int i, int j, int len){
        if(dp[i][j][len]!=0)
            return dp[i][j][len]==1;
        // 相等肯定互为扰动
        if(s1.substr(i,len)==s2.substr(j,len)){
            dp[i][j][len]=1;
            return true;
        }
        // 各个字符数都不同肯定不是互为扰动
        if(!check(i,j,len)){
            dp[i][j][len]=-1;
            return false;
        }
        // 到这里长度至少为2，长度为1的已经在上面判断结束了
        for(int k=1;k<len;k++){
            // 不交换
            if(dfs(i,j,k) && dfs(i+k, j+k, len-k)){
                dp[i][j][len]=1;
                return true;
            }
            // 交换
            if(dfs(i,j+len-k,k) && dfs(i+k, j, len-k)){
                dp[i][j][len]=1;
                return true;
            }
        }
        dp[i][j][len]=-1;
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        memset(dp, 0, sizeof(dp));
        this->s1=s1;
        this->s2=s2;
        return dfs(0,0,s1.length());
    }
};