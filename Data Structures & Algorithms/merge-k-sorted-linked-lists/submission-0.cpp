/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(a && b){
            if(a->val < b->val){
                curr->next = a;
                curr = a;
                a = a->next;
            } else{
                curr->next = b;
                curr = b;
                b = b->next;
            }
        }

        curr->next = a ? a : b;

        return dummy.next;

    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty()){
            return nullptr;
        }

        ListNode dummy(0);
        ListNode* curr = &dummy; //final list spot
        curr->next = lists[0];
        curr = curr->next;
        
        for(int i = 1; i < lists.size(); i++){//all lists still have Nodes
            if(lists[i] == nullptr){continue;}
            curr = mergeTwoLists(lists[i], curr);
        }

        return curr;
    }
};
