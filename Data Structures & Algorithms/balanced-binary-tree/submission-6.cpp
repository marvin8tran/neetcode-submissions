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
        return dfs(root)[0] == 1;
    }
private:
    vector<int> dfs(TreeNode* root){
        if(!root){
            return {1, 0};
        }
        
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);


        bool balanced = (l[0] == 1 && r[0] == 1) && (abs(l[1]-r[1]) <= 1);
        int height = 1 + max(l[1], r[1]);

        return {balanced ? 1 : 0, height};
    }
};
