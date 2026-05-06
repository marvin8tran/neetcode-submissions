/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> nodemap;
        //original, copy


        Node* curr = head;
        while(curr != nullptr){
            nodemap[curr] = new Node(curr->val);
            curr = curr->next;
        }


        curr = head;
        while(curr != nullptr){
            nodemap[curr]->next = nodemap[curr->next];
            nodemap[curr]->random = nodemap[curr->random];
            curr = curr->next;
        }

        return nodemap[head];

    }
};
