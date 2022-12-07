class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size()<2)
            return {};
        int l=0,r=nums.size()-1,sum;
        while(l<r){
            sum=nums[l]+nums[r];
            if(sum==target)
                return {nums[l], nums[r]};
            else if(sum<target)
                l++;
            else
                r--;
        }
        return {};
    }
};