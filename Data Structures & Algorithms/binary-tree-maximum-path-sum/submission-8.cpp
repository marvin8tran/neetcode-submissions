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
    int best = INT_MIN;

    int dfs(TreeNode* root){
        if(root == nullptr){return 0;}

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        //check the non root path
        best = max(best, left + root->val + right);

    
        //return better path (root path)
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {

        //dfs returns best root path, best returns best non root path
        return max(best, dfs(root));
    }
};
