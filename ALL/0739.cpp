class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::pair<int, int> pair;
        std::stack<std::pair<int, int>> stk;
        std::vector<int> answer(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            if(stk.empty()){
                stk.push({temperatures[i], i});
            }
            else{
                while(stk.empty() != true && temperatures[i] > stk.top().first){
                    answer[stk.top().second] = i - stk.top().second;
                    stk.pop();
                }
                stk.push({temperatures[i], i});
            }
        }
        return answer;
    }
};