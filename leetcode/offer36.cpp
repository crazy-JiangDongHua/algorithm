/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    void convert(Node* root, Node*& firstNode){
        if(root==nullptr)
            return;
        convert(root->right, firstNode);
        root->right=firstNode;
        if(firstNode!=nullptr)
            firstNode->left=root;
        firstNode=root;
        convert(root->left, firstNode);
    }
public:
    Node* treeToDoublyList(Node* root) {
        Node *firstNode=nullptr;
        // 从最右边开始
        convert(root, firstNode);
        if(firstNode==nullptr)
            return firstNode;
        Node *lastNode=firstNode;
        while(lastNode->right!=nullptr)
            lastNode=lastNode->right;
        firstNode->left=lastNode;
        lastNode->right=firstNode;
        return firstNode;
    }
};