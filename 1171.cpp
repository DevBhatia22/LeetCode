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
    ListNode* removeZeroSumSublists(ListNode* head) {
        std::unordered_map<int, ListNode*> map;
        ListNode* temp = head;
        int prefixSum = 0;
        while(temp){
            prefixSum += temp->val;
            if(prefixSum == 0){
                temp = temp->next;
                head = temp;
                map.clear();
                prefixSum = 0;
            }
            else{
                if(map[prefixSum]){
                    int tempNum = prefixSum;
                    ListNode* temp1 = map[tempNum]->next;
                    while(temp1 != temp){
                        tempNum += temp1->val;
                        std::cout<<tempNum;
                        map[tempNum] = NULL;
                        temp1 = temp1->next;
                    }
                    map[prefixSum]->next = temp->next;
                }
                else{
                    map[prefixSum] = temp;
                }
                temp = temp->next;
            }
        }
        return head;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();