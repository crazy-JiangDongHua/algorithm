// 快慢指针，重复赋值
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lo=0,hi=0;
        for(;hi<nums.size();hi++){
            if(nums[hi]!=val){
                nums[lo++]=nums[hi];
            }
        }
        return lo;
    }
};

// 对撞指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lo=0,hi=nums.size();
        while(lo<hi){
            if(nums[lo]==val){
                nums[lo]=nums[--hi];
            }else{
                lo++;
            }
        }
        return lo;
    }
};