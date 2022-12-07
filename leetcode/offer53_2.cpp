class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0, r=nums.size(), m;
        while(l<r){
            m=l+((r-l)>>1);
            if(nums[m]==m){
                l=m+1;
            }else{
                r=m;
            }
        }
        return l;
    }
};