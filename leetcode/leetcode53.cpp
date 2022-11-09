// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0,ans=nums[0];
        for(int& x:nums){
            pre=pre>0?pre+x:x;
            ans=max(pre,ans);
        }
        return ans;
    }
};

// 分治
class Solution {
private:
    int myfun(vector<int>& nums, int lo, int hi){
        if(lo+1==hi)return nums[lo];
        int mi=(lo+hi)/2;
        int lsum=myfun(nums, lo, mi);
        int rsum=myfun(nums, mi, hi);
        int s1=INT_MIN, ls=0;
        for(int i=mi-1;i>=lo;i--){
            ls+=nums[i];
            s1=max(ls,s1);
        }
        int s2=INT_MIN, rs=0;
        for(int i=mi;i<hi;i++){
            rs+=nums[i];
            s2=max(rs,s2);
        }
        return max(s1+s2, max(lsum, rsum));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return myfun(nums, 0, nums.size());
    }
};