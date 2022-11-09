class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        while(lo <= hi)
        {
            int mi = lo + (hi-lo)/2;
            if(nums[mi] == target)
                return mi;
            if(nums[lo] <= nums[mi]) //[lo, mi)有序
            {
                if(nums[lo]<=target && target<nums[mi])
                    hi = mi-1;
                else
                    lo = mi+1;
            }
            else //[mi, hi)有序
            {
                if(nums[mi]<target && target<=nums[hi])
                    lo = mi+1;
                else
                    hi = mi-1;
            }
        }
        return -1;
    }
};
