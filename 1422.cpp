class Solution {
public:
    int maxScore(string s) {
        std::vector<int> vec(s.length(), 0);
        int temp = 0;
        for(int i = 0; i < vec.size(); i++){
            if(s[i] == '0'){
                temp++;
            }
            vec[i] = temp;
        }
        int count = 0;
        if(s[s.length() - 1] == '1'){
            count++;
        }
        int answer = 0;
        for(int i = vec.size() - 2; i >= 0; i--){
            if(count + vec[i] > answer){
                answer = count + vec[i];
            }
            if(s[i] == '1'){
                count++;
            }
        }
        return answer;
    }
};