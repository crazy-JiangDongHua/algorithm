class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 边界情况
        int n=nums.size();
        if(n<2)return -1;
        // 避免错误输入
        for(int& num:nums)
            if(num<0)
                return -1;
        for(int i=0;i<n;i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};


// 不修改数组求重复数字
class Solution {
private:
    int count(vector<int>& nums, int l, int r){
        int cnt=0;
        for(int& num:nums){
            if(l<=num && num<=r)
                cnt++;
        }
        return cnt;
    }
public:
    int findRepeatNumber(vector<int>& nums) {
        // 边界情况
        int n=nums.size();
        if(n<2)return -1;
        // 避免错误输入
        for(int& num:nums)
            if(num<0)
                return -1;
        int l=0, r=n-1;
        while(l<=r){
            int m=((r-l)>>1)+l;
            int cnt=count(nums, l, m);
            if(l==r){
                if(cnt>1)
                    return l;
                else
                    return -1;
            }
            if(cnt>m-l+1){
                r=m;
            }else{
                l=m+1;
            }
        }
        return -1;
    }
};