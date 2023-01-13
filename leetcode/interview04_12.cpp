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
    int pathSum(TreeNode* root, int target, int sum, unordered_map<int, int>& hash){
        if(root==nullptr)
            return 0;
        int sumy=sum+root->val;
        int total=0;
        if(hash.count(sumy-target))
            total+=hash[sumy-target];
        hash[sumy]++;
        total+=pathSum(root->left, target, sumy, hash);
        total+=pathSum(root->right, target, sumy, hash);
        hash[sumy]--;
        if(hash[sumy]==0)
            hash.erase(sumy);
        return total;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> hash={{0, 1}};
        return pathSum(root, sum, 0, hash);
    }
};