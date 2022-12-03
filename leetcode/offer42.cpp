class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cumsum=0, ans=INT_MIN;
        for(int& num:nums){
            if(cumsum<=0){
                cumsum=num;
            }else{
                cumsum+=num;
            }
            ans=max(ans, cumsum);
        }
        return ans;
    }
};