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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        int count = 0;
        ListNode* even = head->next;
        ListNode* current = head;
        ListNode* next = head->next;
        while(current->next->next){
            current->next = next->next;
            current = next;
            next = next->next;
            count++;
        }
        if(count%2){
            current->next = NULL;
            next->next = even;
            return head;
        }
        else{
            current->next = even;
            next->next = NULL;
            return head;
        }
        
    }
};