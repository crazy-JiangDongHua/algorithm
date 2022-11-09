class Solution {
private:
    TreeNode* create(vector<int>& preSq, vector<int>& inSq, int preL, int preR,
                    int inL, int inR){
        if(inL>=inR)return nullptr;
        TreeNode* root=new TreeNode(preSq[preL]);
        int k;
        for(k=inL;k<inR;k++)if(inSq[k]==root->val)break;
        int leftnum=k-inL;
        root->left=create(preSq, inSq, preL+1, preL+1+leftnum, inL, k);
        root->right=create(preSq, inSq, preL+1+leftnum, preR, k+1, inR);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, inorder, 0, preorder.size(), 0, preorder.size());
    }
};