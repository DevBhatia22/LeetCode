class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::vector<int> answer(nums.size(), -1);
        std::stack<int> stk;
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!stk.empty() && nums[i] >= stk.top()){
                stk.pop();
            }
            if(!stk.empty()){
                answer[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!stk.empty() && nums[i] >= stk.top()){
                stk.pop();
            }
            if(!stk.empty()){
                answer[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();