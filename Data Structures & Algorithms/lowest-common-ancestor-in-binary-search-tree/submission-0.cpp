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
private:
    bool nodeExists(TreeNode* root, TreeNode* a){
        if(root == nullptr){
            return false;
        }
        if(a == nullptr || root == a){
            return true;
        }
        return (nodeExists(root->left, a) || nodeExists(root->right, a));

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        TreeNode* res = root;
        while(!nodeQ.empty()){
            int levelSize = nodeQ.size();

            for(int i = 0; i < levelSize; i++){
                TreeNode* tmp = nodeQ.front();
                nodeQ.pop();
                if(nodeExists(tmp, p) && nodeExists(tmp, q)){
                    res = tmp;
                }

                if(tmp->left != nullptr){
                    nodeQ.push(tmp->left);
                }
                if(tmp->right != nullptr){
                    nodeQ.push(tmp->right);
                }
            }
        }
        return res;

    }
};
