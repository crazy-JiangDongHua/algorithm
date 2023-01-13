/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int lo, int hi){
        if(lo>=hi)
            return nullptr;
        int mi=lo+((hi-lo)>>1);
        TreeNode* root=new TreeNode(nums[mi]);
        root->left=sortedArrayToBST(nums, lo, mi);
        root->right=sortedArrayToBST(nums, mi+1, hi);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};