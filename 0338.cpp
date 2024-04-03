class Solution {
public:
    vector<int> countBits(int n) {
        int next = 1;
        std::vector<int> answer(n + 1);
        answer[0] = 0;
        int adder = 0;
        for(int i = 1; i <= n; i++){
            if(i == next){
                next *= 2;
                adder = 1;
                answer[i] = 1;
            }
            else{
                answer[i] = answer[next / 2] + answer[adder];
                adder++;
            }
        }
        return answer;
    }
};