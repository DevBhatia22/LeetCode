class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::vector<int> answer;
        long long lowLen = std::to_string(low).length();
        long long num = -1;
        long long adder = 0;
        while(num <= high){
            if(num % 10 == 9 || num == -1){
                if(num % 10 == 9){
                    if(num >= low){
                        answer.push_back(num);
                    }
                    num += adder;
                }
                num = 0;
                adder = 0;
                for(int i = 0; i < lowLen; i++){
                    num = num * 10 + (i + 1);
                    adder = adder * 10 + 1;
                }
                lowLen++;
            }
            else{
                if(num >= low){
                    answer.push_back(num);
                }
                num += adder;
            }
        }
        return answer;
    }
};