class Solution {
private:
    TreeNode* create(vector<int>& inSq, vector<int>& postSq, int inL, int inR,
                    int postL, int postR){
        if(inL>=inR)return nullptr;
        TreeNode* root=new TreeNode(postSq[postR-1]);
        int k;
        for(k=inL;k<inR;k++)if(inSq[k]==root->val)break;
        int leftnum=k-inL;
        root->left=create(inSq, postSq, inL, k, postL, postL+leftnum);
        root->right=create(inSq, postSq, k+1, inR, postL+leftnum, postR-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(inorder, postorder, 0, inorder.size(), 0, inorder.size());
    }
};