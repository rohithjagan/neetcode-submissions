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
    bool isBalanced(TreeNode* root) {
        return diff(root) != -1;
    }
    int diff(TreeNode*root){
        if(root == nullptr){
            return 0;
        }
        auto x = diff(root->left);
        auto y = diff(root->right);
        if(x==-1 || y==-1){
            return -1;
        }
        if(abs(x-y)>1){
            return -1;
        }
        return 1 + max(x,y);
    }
};
