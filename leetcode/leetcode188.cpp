// 动态规划
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() || k==0)return 0;
        int n=prices.size();
        vector<int> buy(k+1, INT_MIN/2); //不合法状态直接给-INF
        vector<int> sell(k+1, INT_MIN/2);
        buy[0]=-prices[0];
        sell[0]=0;
        for(int i=1;i<n;i++){
            buy[0]=max(buy[0], -prices[i]);
            for(int j=1;j<=k;j++){
                buy[j]=max(buy[j], sell[j]-prices[i]);
                sell[j]=max(sell[j], buy[j-1]+prices[i]);
            }
        }
        int ans=-1;
        for(int i=0;i<=k;i++){
            ans=max(ans, sell[i]);
        }
        return ans;
    }
};

// 最大m子段和
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() || k==0)return 0;
        int n=prices.size();
        if(n==1)return 0;
        vector<int> arr(n);
        for(int i=1;i<=n-1;i++)
            arr[i]=prices[i]-prices[i-1];
        vector<vector<int>> dp(2, vector<int>(n));
        for(int i=0;i<=n-1;i++){
            dp[0][i]=0;
        }
        int ans=0;
        for(int i=1,p=1;i<=k;i++,p^=1){
            dp[p][i-1]=INT_MIN;
            int maxpre=INT_MIN;
            for(int j=i;j<=n-1;j++){
                maxpre=max(maxpre, dp[p^1][j-1]);
                dp[p][j]=max(dp[p][j-1],maxpre)+arr[j];
                ans=max(ans,dp[p][j]);
            }
        }
        return ans;
    }
};