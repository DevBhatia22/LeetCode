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
    bool hasCycle(ListNode *head) {
        std::ios_base::sync_with_stdio(false);
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare && hare->next){
            tortoise=tortoise->next;
            hare=hare->next->next;
            if(hare==tortoise){
                return true;
            }
        }
        return false;
    }
};