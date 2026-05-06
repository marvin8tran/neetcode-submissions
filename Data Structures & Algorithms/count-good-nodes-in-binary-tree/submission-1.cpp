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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* root, int maxX){
        if(root == nullptr){
            return 0;
        }
        if(root->val >= maxX){
            return dfs(root->right, root->val) + dfs(root->left, root->val) + 1;
        } else{
            return dfs(root->right, maxX) + dfs(root->left, maxX);
        }
    }
};
