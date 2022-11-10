// 动态规划
class Solution {
public:
    int cuttingRope(int n) {
        if(n==1)return 1;
        if(n==2)return 1;
        if(n==3)return 2;
        vector<int> dp(n+1, 0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i]=max(dp[i], dp[j]*dp[i-j]);
            }
        }
        return dp[n];
    }
};

// 贪心
class Solution {
public:
    int cuttingRope(int n) {
        if(n==1)return 1;
        if(n==2)return 1;
        if(n==3)return 2;
        int num3=n/3;
        if(n-num3*3==1)
            num3--;
        int num2=(n-num3*3)/2;

        long long ans=1, mod=1e9+7;
        // 此处可以用快速幂优化
        for(int i=0;i<num3;i++)
            ans=ans*3%mod;
        for(int i=0;i<num2;i++)
            ans=ans*2%mod;
        return ans;
    }
};