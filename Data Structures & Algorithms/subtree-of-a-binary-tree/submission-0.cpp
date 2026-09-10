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
    bool check(TreeNode* root, TreeNode* sub){
        if(root == nullptr && sub == nullptr){
            return true;
        }
        if(root == nullptr || sub == nullptr){
            return false;
        }
        if(root->val != sub->val){
            return false;
        }
        return check(root->left,sub->left) && check(root->right,sub->right);
    }
    bool traverse(TreeNode* root, TreeNode* sub){
        if(root == nullptr){
            return false;
        }
        if (check(root, sub)){
            return true;
        }
        return traverse(root->left, sub) || traverse(root->right, sub);
    }
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        return traverse(root,sub);
    }
};
