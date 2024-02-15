/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        bool phlag=true;
        while(hare && hare->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(tortoise==hare){
                phlag = false;
                break;
            }
        }
        if(phlag){
            return NULL;
        }
        hare=head;
        while(hare!=tortoise){
            hare = hare->next;
            tortoise = tortoise->next;
        }
        return hare;
    }
}; 