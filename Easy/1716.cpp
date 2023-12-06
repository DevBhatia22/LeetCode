class Solution {
public:
//test run
    int totalMoney(int n) {
        int onMonday = 1, current = 1, answer = 0;
        for(int i = 0; i < n; i++){
            if(!(i%7)){
                answer += onMonday;
                onMonday++;
                current = onMonday;
            }
            else{
                answer += current;
                current++;
            }
        }
        return answer;
    }
};