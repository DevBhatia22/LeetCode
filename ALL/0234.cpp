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
    bool isPalindrome(ListNode* head) {
        std::stack<int> stk;
        ListNode* tortoise = head;
        ListNode* hare = head;
        int count = 1;

        while(tortoise->next){
            tortoise = tortoise->next;
            count++;
        }
        tortoise = head;
        for(int i = 0; i < count / 2; i++){
            stk.push(head->val);
            head = head->next;
            tortoise = tortoise->next;
        }
        if(count%2){
            tortoise = tortoise->next;
        }
        while(!stk.empty() && tortoise){
            if(stk.top()==tortoise->val){
                stk.pop();
                tortoise = tortoise->next;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};