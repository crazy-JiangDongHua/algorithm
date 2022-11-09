class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 1);
        int p2=1, p3=1, p5=1;
        for(int i=2;i<=n;i++)
        {
            int num1 = dp[p2]*2;
            int num2 = dp[p3]*3;
            int num3 = dp[p5]*5;
            dp[i] = min(min(num1,num2),num3);
            if(dp[i] == num1)
                p2++;
            if(dp[i] == num2)
                p3++;
            if(dp[i] == num3)
                p5++;
        }
        return dp[n];
    }
};
