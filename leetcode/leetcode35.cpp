class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();
        while(lo < hi)
        {
            int mi = lo + (hi-lo)/2;
            if(nums[mi]>=target)
                hi = mi;
            else
                lo = mi + 1;
        }
        return lo;
    }
};
