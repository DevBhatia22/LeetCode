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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<std::pair<int, ListNode*>> queue;
        for(ListNode* i:lists){
            ListNode* temp = i;
            while(temp){
                queue.push({-temp->val, temp});
                temp = temp->next;
            }
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(queue.empty() != true){
            if(head == NULL){
                head = queue.top().second;
                tail = head;
                queue.pop();
                continue;
            }
            tail->next = queue.top().second;
            tail = queue.top().second;
            queue.pop();
        }
        if(head == NULL){
            return head;
        }
        tail->next = NULL;
        return head;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();