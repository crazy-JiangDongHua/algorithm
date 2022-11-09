// 一遍遍历
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int income = 0;
        int curmin = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            income = max(income, prices[i]-curmin);
            curmin = min(curmin, prices[i]);
        }
        return income;
    }
};

// 最大子段和
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1)return 0;
        vector<int> arr(n-1);
        for(int i=0;i<n-1;i++)
            arr[i]=prices[i+1]-prices[i];
        int dp=arr[0];
        int ans=max(0, dp);
        for(int i=1;i<n-1;i++){
            dp=dp>0?arr[i]+dp:arr[i];
            ans=max(ans,dp);
        }
        return ans;
    }
};
