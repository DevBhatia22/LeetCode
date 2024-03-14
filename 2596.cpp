class Solution {
private:
    void dfs(int& num, int x, int y, std::vector<std::vector<int>>& grid){
        int temp[] = {-2, -1, 1, 2, 2, 1, -1, -2, -2, -1};
        for(int i = 0; i < 8; i++){
            int X = x + temp[i];
            int Y = y + temp[i + 2];
            if(X < grid.size() && X >= 0 && Y < grid.size() && Y >= 0 && grid[X][Y] == num + 1){
                num++;
                dfs(num, X, Y, grid);
                return;
            }
        }
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]){
            return false;
        }
        int answer = 0;
        dfs(answer, 0, 0, grid);
        return answer == grid.size() * grid.size() - 1;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();