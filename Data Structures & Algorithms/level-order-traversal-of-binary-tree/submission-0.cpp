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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> output;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* f = q.front();
                temp.push_back(f->val);
                if(f->left != nullptr){
                    q.push(f->left);
                }
                if(f->right != nullptr){
                    q.push(f->right);
                }
                q.pop();
            }
            output.push_back(temp);
            temp.clear();
        }
        return output;
    }
};
