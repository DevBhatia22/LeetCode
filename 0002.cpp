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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int answer=0;
        int carryover=0;
        ListNode *hello = new ListNode();
        ListNode *head=hello;
        int val1=-1;

        while(l1->next!=nullptr || l2->next!=nullptr){
            val1=l1->val+l2->val+carryover;
            hello->val=(val1)%10;
            carryover=val1/10;
            val1=l1->val+l2->val+carryover;
            if(l1->next!=nullptr){
                l1=l1->next;
            }
            else{
                l1->val=0;
            }
            if(l2->next!=nullptr){
                l2=l2->next;
            }
            else{
                l2->val=0;
            }
            val1=l1->val+l2->val+carryover;
            hello->next=new ListNode();
            hello=hello->next;
        }
        val1=l1->val+l2->val+carryover;
        hello->val=(val1)%10;
        carryover=val1/10;
        if(carryover!=0){
            hello->next=new ListNode();
            hello=hello->next;
            hello->val=carryover;
        }
        std::cout<<std::flush;
        return head;
    }
};