class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!i && !j){
                    continue;
                }
                int up = INT_MAX, left = INT_MAX;
                if(i){
                    up = grid[i - 1][j];
                }
                if(j){
                    left = grid[i][j - 1];
                }
                grid[i][j] += std::min(up, left);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();