class Solution {
private:
    int low_bound(vector<int>& nums, int target){
        int l=0, r=nums.size(),m;
        while(l<r){
            m=l+((r-l)>>1);
            if(nums[m]<target){
                l=m+1;
            }else{
                r=m;
            }
        }
        return l;
    }
    int up_bound(vector<int>& nums, int target){
        int l=0, r=nums.size(),m;
        while(l<r){
            m=l+((r-l)>>1);
            if(nums[m]<=target){
                l=m+1;
            }else{
                r=m;
            }
        }
        return l;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int low=low_bound(nums, target);
        if(low>=nums.size() || nums[low]>target)
            return 0;
        int up=up_bound(nums, target);
        return up-low;
    }
};