/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法一 bfs
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if(tree==nullptr)
            return {};
        vector<ListNode*> ans;
        queue<TreeNode*> q;
        q.push(tree);
        ListNode dummy(-1), *cur=&dummy;
        ans.push_back(new ListNode(tree->val));
        while(!q.empty()){
            for(int i=0, n=q.size();i<n;i++){
                tree=q.front();
                q.pop();
                if(tree->left!=nullptr){
                    q.push(tree->left);
                    cur->next=new ListNode(tree->left->val);
                    cur=cur->next;
                }
                if(tree->right!=nullptr){
                    q.push(tree->right);
                    cur->next=new ListNode(tree->right->val);
                    cur=cur->next;
                }
            }
            if(dummy.next!=nullptr){
                ans.push_back(dummy.next);
                cur=&dummy;
                cur->next=nullptr;
            }
        }
        return ans;
    }
};


// 方法二 dfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(vector<ListNode*>& lists, vector<ListNode*>& tails, TreeNode* tree, int level){
        if(tree==nullptr)
            return;
        if(lists.size()<=level){
            lists.push_back(new ListNode(tree->val));
            tails.push_back(lists[level]);
        }else{
            tails[level]->next=new ListNode(tree->val);
            tails[level]=tails[level]->next;
        }
        dfs(lists, tails, tree->left, level+1);
        dfs(lists, tails, tree->right, level+1);
    }
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;
        vector<ListNode*> tails;
        dfs(ans, tails, tree, 0);
        return ans;    
    }
};