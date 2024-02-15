class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int answer = -1;
        if(n > haystack.length()){
            return answer;
        }
        for(int i = 0; i < haystack.length() - n + 1; i++){
            std::string temp = haystack.substr(i, n);
            if(temp == needle){
                answer = i;
                break;
            }
        }
        return answer;
    }
};
auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();