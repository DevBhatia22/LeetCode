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
    int pairSum(ListNode* head) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        ListNode *h=head;
        int len=1;
        while(!(h->next==nullptr)){
            len++;
            h=h->next;
        }
        h=head;
        std::stack<int> s;
        int max_value=0;
        while(max_value++<len/2){
            s.push(h->val);
            h=h->next;
        }
        max_value=0;
        int x;
        while(!s.empty()){
            x=s.top()+h->val;
            s.pop();
            h=h->next;
            if(max_value<=x){
                max_value=x;
            }
        }
        std::cout<<std::flush;
        return max_value;
    }
};