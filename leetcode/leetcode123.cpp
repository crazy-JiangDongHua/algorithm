// 动态规划

// 最大m子段和

// 逆天写法，收下我的膝盖
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)return 0;
        int n=prices.size();
        vector<int> L(n,0), R(n,0);
        int lmin=prices[0], rmax=prices[n-1];
        for(int i=1;i<n;i++){
            lmin=min(lmin,prices[i]);
            L[i]=max(L[i-1],prices[i]-lmin);
        }
        for(int i=n-2;i>=0;i--){
            rmax=max(rmax,prices[i]);
            R[i]=max(R[i+1],rmax-prices[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(L[i]+R[i], ans);
        return ans;
    }
};