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
    vector<int> nums;
    
    int kthSmallest(TreeNode* root, int k) {
        //binary = 2 child per parent
        storeNums(root);

        return nums[k - 1];
        
    }

    void storeNums(TreeNode* root){
        if(root == nullptr){
            return;
        }
        storeNums(root->left);
        nums.push_back(root->val);
        storeNums(root->right);

        return;

    }
};
