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
    ListNode* deleteMiddle(ListNode* head) {
        std::ios_base::sync_with_stdio(false);
        if(!head->next){
            return NULL;
        }
        
        
        
        ListNode* tortoise = head;
        ListNode* prev =NULL;
        ListNode* hare =head;
        
        
        
        while(hare && hare->next){
            prev = tortoise;
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        
        prev->next = tortoise->next;
        delete tortoise;
        return head;
    }
};