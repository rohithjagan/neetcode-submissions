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
    TreeNode* x;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            auto temp = p;
            p = q;
            q = temp;
        }
        if(p->val<=root->val && root->val<=q->val){
            x = root;
            return x;
        }
        else if(p->val<root->val && q->val<root->val){
            lowestCommonAncestor(root->left,p,q);
        }
        else{
            lowestCommonAncestor(root->right,p,q);
        }
        return x;
    }
};
