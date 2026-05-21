/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr, unordered_map<Node*, Node*>& seen){

        if(curr == nullptr){return nullptr;}
        if(seen.count(curr)){return seen[curr];} //return clone

        Node* clone = new Node(curr->val);
        seen[curr] = clone;

        for(Node* n : curr->neighbors){
            clone->neighbors.push_back(dfs(n, seen));
        }

        return clone;


    }


    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> seen; //original -> clone
        return dfs(node, seen);        
    }
};
