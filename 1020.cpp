class Solution {
private:
    // std::vector<std::vector<bool>> visited;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // visited.resize(grid.size(), std::vector<bool>(grid[0].size(), 0));
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0 || i == grid.size() - 1 || j == 0 ||
                    j == grid[i].size() - 1) {
                    if (grid[i][j] == 1) {
                        // visited[i][j] = true;
                        grid[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
        }
        while (q.empty() != true) {
            std::vector<int> temp({-1, 0, 1, 0, -1});
            for (int i = 0; i < 4; i++) {
                int newi = q.front().first + temp[i];
                int newj = q.front().second + temp[i + 1];
                if (newi >= 0 && newi < grid.size() && newj >= 0 &&
                    newj < grid[0].size() && grid[newi][newj] == 1) {
                    q.push({newi, newj});
                    grid[newi][newj] = 0;
                    // visited[newi][newj] = true;
                }
            }
            q.pop();
        }
        int answer = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    answer++;
                }
            }
        }
        return answer;
    }
};
auto init = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();