class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int income=0, i=0, j=1;
        for(;j<prices.size();j++)
        {
            if(prices[j]<prices[j-1])
            {
                income += prices[j-1] - prices[i];
                i = j;
            }
        }
        income += prices[j-1] - prices[i];
        return income;
    }
};
