/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insert(TreeNode* root,int val){
        if(val<root->val && root->left == nullptr){
            TreeNode* temp = new TreeNode(val);
            root->left = temp;
            return;
        }
        if(val>root->val && root->right == nullptr){
            TreeNode* temp = new TreeNode(val);
            root->right = temp;
            return;
        }
        if(val<root->val){
            insert(root->left,val);
        }
        if(val>root->val){
            insert(root->right,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }
        insert(root,val);
        return root;
    }
};