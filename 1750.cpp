class Solution {
public:
    int minimumLength(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end){
            if(s[start] == s[end]){
                char c = s[start];
                while(start <= end && s[start] == c){
                    start++;
                }
                while(start <= end && s[end] == c){
                    end--;
                }
            }
            else{
                break;
            }
        }
        return end - start + 1;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();