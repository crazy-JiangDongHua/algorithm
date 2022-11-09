class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        while(lo<=hi){
            int mi=(lo+hi)/2;
            if(nums[mi]==target)
                return true;
            // 无法判断哪个区间是有序的
            if(nums[lo]==nums[mi] && nums[mi]==nums[hi]){
                lo++;hi--;
            }else if(nums[lo]<=nums[mi]){
                if(nums[lo]<=target && target<nums[mi]){
                    hi=mi-1;
                }else{
                    lo=mi+1;
                }
            }else{
                if(nums[mi]<target && target<=nums[hi]){
                    lo=mi+1;
                }else{
                    hi=mi-1;
                }
            }
        }
        return false;
    }
};