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
    ListNode* reverseKTimes(ListNode* a, int k){   


        ListNode* prev = nullptr; //group end ->next
        ListNode* curr = a;
        
        for(int j = 0; j < k; j++){
                ListNode* temp = curr->next; // save 2
                curr->next = prev; //flip null <- 1
                prev = curr; //new prev = 1
                curr = temp; //new curr = 2
            }

        return prev;   //return head fine....
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        

        ListNode dummy(0);
        ListNode* prev = &dummy;
        ListNode* curr = head;


        while(curr){
            ListNode* start = curr;
        
            //curr = start of next group
            int i = 0;
            while(curr && i < k){
                curr = curr->next;
                i++;
            }

            if(i < k){break;}

            
            prev->next = reverseKTimes(start, k); // dummy points at 3
            start->next = curr;
            prev = start;
        }

        return dummy.next;
    }
};
