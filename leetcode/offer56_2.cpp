class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
            throw exception();
        int cnt[32]={0}, bit;
        for(const int& num:nums){
            bit=1;
            for(int i=31;i>=0;i--){
                cnt[i]+=((num&bit)!=0?1:0);
                if(i>0)
                    bit<<=1;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            ans=(ans<<1) + cnt[i]%3;
        }
        return ans;
    }
};