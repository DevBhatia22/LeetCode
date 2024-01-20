class Solution {
public:
    int visited[11][11];
    int bfs(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>& q){
        int time = -1;
        std::vector<int> row({-1, 0, 1, 0});
        std::vector<int> column({0, -1, 0, 1});
        while(q.empty() != true){
            int runs = q.size();
            int temp = 0;
            while(temp < runs){
                int I = q.front().first;
                int J = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nI = I + row[i];
                    int nJ = J + column[i];
                    if(nI >= 0 && nJ >= 0 && nI < grid.size() && nJ < grid[0].size() && grid[nI][nJ] == 1 && visited[nI][nJ] == false){
                        q.push({nI, nJ});
                        visited[nI][nJ] = true;
                    }
                }
                temp++;
            }
            time++;
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;
        int answer = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        answer = std::max(0, bfs(grid, q));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && visited[i][j] != true){
                    answer = -1;
                }
            }
        }
        return answer;
    }
};