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
    ListNode* reverse(ListNode* root){
        if(!root->next){
            return root;
        }
        ListNode* temp = reverse(root->next);
        root->next->next = root;
        root->next = NULL;
        return temp;
    }
    void reorderList(ListNode* head) {
        if(!head->next){
            return;
        }
        ListNode* tortoise = head;
        ListNode* hare = head;
        ListNode* prev = NULL;
        while(hare && hare->next){
            prev = tortoise;
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        tortoise = reverse(tortoise);
        prev->next = NULL;
        hare = head;
        while(hare){
            ListNode* temp1 = hare->next;
            ListNode* temp2 = tortoise->next;
            if(!temp1){
                hare->next = tortoise;
                break;
            }
            hare->next = tortoise;
            tortoise->next = temp1;
            hare = temp1;
            tortoise = temp2;
        }
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();