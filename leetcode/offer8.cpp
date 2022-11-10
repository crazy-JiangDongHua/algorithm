struct TreeNode{
    int val;
    TreeNode *lc, *rc, *father;
};

TreeNode* succ(TreeNode* pNode){
    if(pNode==nullptr)
        return nullptr;
    if(pNode->rc!=nullptr){
        pNode=pNode->rc;
        while(pNode->lc!=nullptr)
            pNode=pNode->lc;
    }else{
        while (pNode->father!=nullptr && pNode->father->lc!=pNode){
            pNode=pNode->father;
        }
        pNode=pNode->father;
    }
    return pNode;
}

