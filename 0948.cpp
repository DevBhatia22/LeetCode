class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int start = 0, end = tokens.size() - 1;
        int max = 0;
        std::sort(tokens.begin(), tokens.end());
        while(start <= end){
            if(power >= tokens[start]){
                power -= tokens[start++];
                score++;
            }
            else if(score > 0){
                power += tokens[end--];
                score--;
            }
            else{
                return max;
            }
            if(score > max){
                max = score;
            }
        }
        return max;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();