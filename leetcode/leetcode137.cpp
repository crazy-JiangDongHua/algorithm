class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0,p;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int& num:nums){
                cnt+=num&1;
                num=num>>1;
            }
            if(i==0)p=1;
            else p=p<<1;
            if(cnt%3!=0)
                ans=ans|p;
        }
        return ans;
    }
};