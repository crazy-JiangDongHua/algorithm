/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* sub_deserialize(queue<string>& q){
        string s=q.front();q.pop();
        if(s=="$")
            return nullptr;
        TreeNode* root=new TreeNode(stoi(s));
        root->left=sub_deserialize(q);
        root->right=sub_deserialize(q);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)
            return string("$,");
        string ans=to_string(root->val)+",";
        ans+=serialize(root->left);
        ans+=serialize(root->right);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string tmp;
        for(char& c:data){
            if(c==','){
                q.push(tmp);
                tmp.clear();
            }else{
                tmp.push_back(c);
            }
        }

        return sub_deserialize(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));