class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(!grid.size() || grid[0][0]){
            return -1;
        }
        std::queue<std::pair<int, int>> queue;
        queue.push({0, 0});
        int answer = 1;
        std::vector<int> temp({1, 1, 1, 0, -1, -1, -1, 0, 1, 1});
        grid[0][0] = 1;
        
        while(!queue.empty()){
            int size = queue.size();
            if(queue.front().first == grid.size() - 1 && queue.front().second == grid.size() - 1){
                return answer;
            }
            answer++;
            while(size--){
                for(int i = 0; i < 8; i++){
                    int x = queue.front().first + temp[i];
                    int y = queue.front().second + temp[i + 2];
                    if(x >= 0 && x < grid.size() && y >= 0 && y < grid.size() && grid[x][y] == 0){
                        grid[x][y] = 1;
                        if(x == grid.size() - 1 && y == grid.size() - 1){
                            return answer;
                        }
                        queue.push({x, y});
                    }
                }
                queue.pop();
            }
        }
        return -1;
    }
};