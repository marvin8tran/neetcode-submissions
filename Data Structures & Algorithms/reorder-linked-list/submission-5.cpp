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
    void reorderList(ListNode* head) {



        // 0 1 2 3
        // 0 3 1 2
        //first last 2dfirst 2dlast
        //0 1 2

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow = mid point, fast = end of list
        //0 1, 2 3
        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;

        ListNode* next;
        
        while(curr){
            next = curr->next; //save 2
            curr->next = prev; //1 -> nullptr
            prev = curr; // prev = 1
            curr = next; // curr = 2
        }
        
        slow = head;


        while(prev){
            ListNode* tmp1 = slow->next;
            ListNode* tmp2 = prev->next;

            slow->next = prev;
            prev->next = tmp1;

            slow = tmp1;
            prev = tmp2;
        }


            


    }
};
