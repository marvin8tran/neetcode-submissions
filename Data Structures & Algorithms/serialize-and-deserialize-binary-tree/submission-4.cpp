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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "N";
        }
        
        string val = to_string(root->val);
        return(val + "," + serialize(root->left) + "," + serialize(root->right));
        

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s = "";
        for(char c : data){
            if(c == ','){
                q.push(s);
                s = "";
            } else {
                s += c;
            }
        }
        q.push(s);

        return dfsdeserialize(q);
    }

    TreeNode* dfsdeserialize(queue<string>& qu){
        
        if(qu.empty()){
            return nullptr;
        }

        if(qu.front() == "N"){
            qu.pop();
            return nullptr;
        }

        int val = stoi(qu.front());
        TreeNode* root = new TreeNode(val);
        qu.pop();

        root->left = dfsdeserialize(qu);
        root->right = dfsdeserialize(qu);

        return root;


    }
};
