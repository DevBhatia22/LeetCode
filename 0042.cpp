class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<int> stk;
        int answer = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int temp = height[stk.top()];
                stk.pop();
                if(stk.empty()){
                    break;
                }
                answer += (std::min(height[stk.top()], height[i]) - temp) *
                          (i - stk.top() - 1);
            }
            stk.push(i);
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