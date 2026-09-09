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
    int val = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return val;
    }
    int diameter(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int x = diameter(root->left);
        int y = diameter(root->right);
        val = max(val,x+y);
        return 1+max(x,y);
    }
};
