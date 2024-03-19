class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        std::stack<int> stk;
        std::vector<int> left(arr.size()), right(arr.size());
        for(int i = 0; i < arr.size(); i++){
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                left[i] = stk.top();
            }
            else{
                left[i] = -1;
            }
            stk.push(i);
        }
        stk = std::stack<int>();
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                right[i] = stk.top();
            }
            else{
                right[i] = arr.size();
            }
            stk.push(i);
        }
        long long answer = 0;
        for(int i = 0; i < left.size(); i++){
            answer += (long long)(i - left[i]) * (right[i] - i) % int(1e9 + 7) * arr[i];
            answer %= int(1e9 + 7);
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