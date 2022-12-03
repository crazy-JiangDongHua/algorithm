class Solution {
private:
    bool check(int i, const string& s){
        return '1'==s[i-1] || (s[i-1]=='2' && '0'<=s[i] && s[i]<='5');
    }
public:
    int translateNum(int num) {
        // bad input
        if(num<0)
            return -1;
        string s=to_string(num);
        int n=s.length();
        vector<int> dp(n, 0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            if(check(i, s)){
                if(i>2)
                    dp[i]+=dp[i-2];
                else
                    dp[i]+=1;
            }
        }
        return dp[n-1];
    }
};