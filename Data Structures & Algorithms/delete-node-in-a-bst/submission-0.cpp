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
    void removeNode(TreeNode*& root, int key) {
        if (root == nullptr) {
            return;
        }
        if (key < root->val) {
            removeNode(root->left, key);
        }
        else if (key > root->val) {
            removeNode(root->right, key);
        }
        else {
            if (root->left == nullptr) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == nullptr) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else {
                TreeNode* successor = root->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }
                root->val = successor->val;
                removeNode(root->right, successor->val);
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        removeNode(root, key);
        return root;
    }
};