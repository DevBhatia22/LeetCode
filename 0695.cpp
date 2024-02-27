class Solution {
public:
    std::vector<std::vector<bool>> visited;
    std::vector<int> temp;
    int dfs(std::vector<std::vector<int>>& grid, int i, int j){
        visited[i][j] = 1;
        int count = 1;
        for(int k = 0; k < 4; k++){
            int newI = i + temp[k];
            int newJ = j + temp[k + 1];
            if(newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[newI].size() && !visited[newI][newJ] && grid[newI][newJ] == 1){
                count += dfs(grid, newI, newJ);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        visited.resize(grid.size(), std::vector<bool>(grid[0].size(), 0));
        temp = {-1, 0, 1, 0, -1};
        int answer = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    answer = std::max(dfs(grid, i, j), answer);
                }
            }
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();