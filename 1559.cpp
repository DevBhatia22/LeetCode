class Solution {
private:
    std::vector<std::vector<char>> frequency;
    std::vector<int> temp{-1, 0, 1, 0, -1};
    bool dfs(std::vector<std::vector<char>>& grid, int x, int y, int prevX, int prevY){
        frequency[x][y] = 1;
        int n = grid.size();
        int m = grid[x].size();
        for(int i = 0; i < 4; i++){
            int X = x + temp[i];
            int Y = y + temp[i + 1];
            if(X >= 0 && X < n && Y >= 0 && Y < m && grid[X][Y] == grid[x][y] && (X != prevX || Y != prevY)){
                if(frequency[X][Y]){
                    return true;
                }
                if(dfs(grid, X, Y, x, y)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        frequency.resize(grid.size(), std::vector<char>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(!frequency[i][j]){
                    if(dfs(grid, i, j, -1, -1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};