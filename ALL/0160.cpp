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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int c1 = 0, c2 = 0;
        ListNode* first = head1;
        ListNode* second = head2;
        while(first){
            c1++;
            first = first->next;
        }
        while(second){
            c2++;
            second = second->next;
        }
        first = head1;
        second = head2;

        if(c1>c2){
            for( int i = 0 ; i < c1 - c2 ; i++ ){
                first = first->next;
            }
        }
        else{
            for( int i = 0 ; i < c2 - c1 ; i++ ){
                second = second->next;
            }
        }

        while(second){
            if(first==second){
                return first;
            }
            first = first->next;
            second = second->next;
        }
        return NULL;
    }
};