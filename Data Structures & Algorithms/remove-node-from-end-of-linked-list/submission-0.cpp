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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode dummy(0); 
        dummy.next = head;

        ListNode* curr = head;

        int count = 0;

        while(curr != nullptr){
            count++;
            curr = curr->next;
        }

        count -= n;
        ListNode* prev = &dummy;

        for(int i = 0; i < count; i++){
            prev = prev->next;
        }

        ListNode* x = prev->next;
        prev->next = x->next;

        delete x;

        return dummy.next;

    }
};
