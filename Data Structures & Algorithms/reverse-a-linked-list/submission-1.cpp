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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        

        // 1 -> 2 -> 3 -> 4
        // 2 -> 1 -> null (head = 2, head->next = 1, 
        // 1->next = null (prev)
        // 
        // prev = head (curr)
        // curr = head->next (but changed)
        // new curr = prev
        // 2 ->next = prev (head if no change)

        // 4 -> 3 -> 2 -> 1

        while(curr){
            ListNode* temp = curr->next; //temp saves 1->2
            curr->next = prev; // 1->2 => 1->null (prev)
            prev = curr; // 
            curr = temp;
            
            




        }
        return prev;

    }
};
