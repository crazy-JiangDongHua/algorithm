class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp=triangle[n-1];
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<i;j++){
                dp[j]=triangle[i-1][j]+min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};