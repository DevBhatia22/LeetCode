class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int answer = 0;
        for(std::string i:operations){
            if(i[0] == '+' || i[2] == '+'){
                answer++;
            }
            else{
                answer--;
            }
        }
        return answer;
    }
};