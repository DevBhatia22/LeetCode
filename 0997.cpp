class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> left(n + 1, 0), right(n + 1, 0);
        for(std::vector<int> i:trust){
            left[i[0]] = 1;
            right[i[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(!left[i] && right[i] == n - 1){
                return i;
            }
            if(!left[i]){
                return -1;
            }
        }
        return -1;
    }
};
auto init = [] (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();