class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> answer;
        for(int i = 0; i < n; i++){
            std::string temp;
            if(!((i + 1) % 3)){
                temp += "Fizz";
            }
            if(!((i + 1) % 5)){
                temp += "Buzz";
            }
            if((i + 1) % 3 && (i + 1) % 5){
                temp += std::to_string(i + 1);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};