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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;

        


        while(!q.empty() && q.front() != nullptr){
            int currentLength = q.size();

            for(int i = 0; i < currentLength - 1; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            TreeNode* x = q.front();
            q.pop();
            res.push_back(x->val);
            if(x->left != nullptr){
                q.push(x->left);
            }
            if(x->right != nullptr){
                q.push(x->right);
            }
        }

        return res;

    }
};
