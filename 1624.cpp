class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int answer = -1;
        std::vector<int> vec(26, -1);
        for(int i = 0; i < s.length(); i++){
            if(vec[s[i] - 'a'] == -1){
                vec[s[i] - 'a'] = i;
            }
            else{
                answer = std::max(answer, i - vec[s[i] - 'a'] - 1);
            }
        }
        return answer;
    }
};