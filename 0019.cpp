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
        if(!head->next){
            return NULL;
        }
        ListNode* traker = head;
        ListNode* current = head;
        ListNode* prev = NULL;
        
        for(int  i = 0 ; i < n ; i++){
            traker = traker->next;
        }
        if(!traker){
            head = head->next;
            return head;
        }
        while(traker){
            prev = current;
            current = current->next;
            traker = traker->next;
        }
        
        prev->next = current->next;
        delete current;
        
        
        
        return head;
    }
};