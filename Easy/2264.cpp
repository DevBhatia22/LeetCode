class Solution {
public:
    string largestGoodInteger(string num) {
        int count = 0;
        char current = num[0];
        char temp = '\0';
        for(char i:num){
            if(i == current){
                count++;
            }
            else{
                count = 1;
                current = i;
            }
            
            if(count >= 3){
                if(temp == '\0'){
                    temp = i;
                }
                else{
                    if(i > temp){
                        temp = i;
                    }
                }
            }
        }
        if(temp == '\0'){
            return "";
        }
        std::string answer(3, temp);
        return answer;
    }
};