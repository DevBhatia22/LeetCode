class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        std::vector<std::vector<int>> answer(2, std::vector<int>(0, 0));
        std::vector<int> temp1, temp2;
        std::unordered_map<int, int> map;
        for(std::vector<int> i:matches){
            if(map[i[0]] == 0){
                map[i[0]] = 0;
            }
            map[i[1]]++;
        }
        for(auto i:map){
            if(i.second == 0){
                temp1.push_back(i.first);
            }
            if(i.second == 1){
                temp2.push_back(i.first);
            }
        }
        std::sort(temp1.begin(), temp1.end());
        std::sort(temp2.begin(), temp2.end());
        answer[0] = temp1;
        answer[1] = temp2;
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();