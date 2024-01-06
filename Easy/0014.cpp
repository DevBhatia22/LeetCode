class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string answer = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int count = 0;
            while(answer[count] == strs[i][count]){
                count++;
                if(count >= answer.length()){
                    break;
                }
            }
            answer = answer.substr(0, count);
        }
        return answer;
    }
};
auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();