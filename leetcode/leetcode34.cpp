class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lo = 0;
        int hi = nums.size();
        vector<int> res = {-1, -1};
        while(lo < hi)
        {
            int mi = lo + (hi - lo)/2;
            if(nums[mi] > target)
                hi = mi;
            else
                lo = mi + 1;
        }
        if(lo-1<0 || nums[lo-1]!=target)
            return res;
        res[1] = lo - 1;
        lo = 0;
        hi = nums.size();
        while(lo < hi)
        {
            int mi = lo + (hi - lo)/2;
            if(nums[mi] >= target)
                hi = mi;
            else
                lo = mi + 1;
        }
        res[0] = lo;
        return res;
    }
};
