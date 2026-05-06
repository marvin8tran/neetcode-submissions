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
        
        queue<TreeNode*> cityboi;
        vector<vector<int>> res;
        cityboi.push(root);

        while(!cityboi.empty()){
            
            int levelSize = cityboi.size();
            vector<int> lev;
            for(int i = 0; i < levelSize; i++){
                TreeNode* tmp = cityboi.front();
                cityboi.pop();

                lev.push_back(tmp->val);

                if(tmp->left != nullptr){
                    cityboi.push(tmp->left);
                }
                if(tmp->right != nullptr){
                    cityboi.push(tmp->right);
                }
            }
            res.push_back(lev);
        }

        return res;


    }
};
