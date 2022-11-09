class Solution {
private:
    TreeNode* gen(vector<int>& nums, int lo, int hi){
        if(lo>=hi)return nullptr;
        int mi=(lo+hi)/2;
        return new TreeNode(nums[mi], gen(nums, lo, mi), gen(nums, mi+1, hi));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return gen(nums, 0, nums.size());
    }
};